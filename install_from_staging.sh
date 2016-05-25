#!/bin/bash

# Go to docroot/
cd docroot/

drush sql-drop -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Error cleaning database"
  exit ${ecode};
fi

pre_update=  post_update= files=
while getopts b:a:f opt; do
  case $opt in
  b)
      pre_update=$OPTARG
      ;;
  a)
      post_update=$OPTARG
      ;;
  f)
      files="files"
      ;;
  esac
done

# Sync from edw staging
drush downsync_sql @staging @self -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "downsync_sql has returned an error"
  exit ${ecode};
fi

drush vset maintenance_mode 1

if [ ! -z "$pre_update" ]; then
  echo "Run pre update"
  ../$pre_update
fi

# Devify - development settings
drush devify --yes
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify has returned an error"
  exit ${ecode};
fi

drush updatedb -y
if [ ${ecode} != 0 ]; then
  echo "updatedb has returned an error"
  exit ${ecode};
fi

# Build the site
#drush osha_build -y
#if [ ${ecode} != 0 ]; then
#  echo "osha_build has returned an error"
#  exit ${ecode};
#fi

drush devify_solr
drush devify_ldap

drush cc all

drush vset maintenance_mode 0

if [ ! -z "$post_update" ]; then
  echo "Run post update"
  ../$post_update
  drush cc all
fi

if [ ! -z "$files" ]; then
echo "Run drush rsync"
drush -y rsync @staging:%files @self:%files --chmod=ug+w
fi

ecode=$?
if [ ${ecode} != 0 ]; then
  echo "rsync has returned an error"
  exit ${ecode};
fi

# Post-install release 3
# drush ne-import --file=../content/internal-doc-webform.drupal
# drush php-script ../scripts/s9/post-update.php
