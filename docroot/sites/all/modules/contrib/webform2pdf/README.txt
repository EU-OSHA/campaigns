Installing webform2pdf Drupal module

0. Module license:
   GNU GPL v2.0

1.Software requirements in the order of the installation:
 - Drupal 7.x - available for download from http://drupal.org/project/drupal
 - Webform Drupal module - available for download from http://drupal.org/project/webform
 - Webform2pdf Drupal module - available for download from http://drupal.org/project/webform2pdf
 - TCPDF - PHP class for generating PDF documents - available for download from http://www.tcpdf.org/

2.Webform2pdf module installation with the TCPDF class:
  2.1 Extract downloaded webform2pdf.tar.gz file:
    $ tar - xvvzf webform2pdf-7.x-*.tar.gz

  2.2 Copy extracted directory to Drupal module directory

  2.3 Extract downloaded TCPDF zip file:
    $ unzip tcpdf_*.zip

  2.4 Copy extracted directory to sites/all/libraries directory

  2.5 Log in to Drupal, as an administrator, and enable webform2pdf module.

3.First steps
  3.1 General settings are available at ?q=admin/settings/webform2pdf.

  3.2 Create a form (or open an existing one), using webform Drupal module.

  3.3 If the installation was successful, "Generate PDF" submenu item will
      appear, when the form is opened for editing. After enabling
      "Generate PDF Document", settings of the generated PDF document will
      appear.
