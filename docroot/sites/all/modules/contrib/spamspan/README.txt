Readme
------

The SpamSpan module obfuscates email addresses to help prevent spambots from
collecting them.  It implements the technique at http://www.spamspan.com

The problem with most email address obfuscators is that they rely upon
JavaScript being enabled on the client side.  This makes the technique
inaccessible to people with screen readers.  SpamSpan however will produce
clickable links if JavaScript is enabled, and will show the email address as
<code>example [at] example [dot] com</code> if the browser does not support
JavaScript or if JavaScript is disabled.

Installation
------------

1. Create a directory in your Drupal modules directory (probably
   sites/all/modules/) called spamspan and copy all of the module's
   files into it.

2. Go to the Modules administration page (admin/modules), and enable the
   spamspan module (under Input Filters)

3. Go to the Text Formats Configuration page (admin/config/content/formats)
   and configure the desired input formats to enable the filter.

4. Rearrange the Filter processing order to resolve conflicts with other 
   filters.  NB: To avoid problems, you should at least make sure that the 
   SpamSpan filter has a higher weighting (greater number) than the line break 
   filter which comes with Drupal ("Convert line breaks into HTML" should come 
   above SpamSpan in the list of Enabled filters).  If you use HTML filter 
   ("Limit allowed HTML tags"), you may need to make sure that <span> is 
   one of the allowed tags. Also, URL filter ("Convert URLs into links") must 
   come after SpamSpan.

5. (optional) Set available options under "Filter Settings". 

Bugs
----

Please report any bugs using the bug tracker at
http://drupal.org/project/issues/spamspan


Module Author
------------
Original: Lawrence Akka : http://drupal.org/user/63367
November 2014 rewrite: Peter Moulding : http://petermoulding.com/spamspan

