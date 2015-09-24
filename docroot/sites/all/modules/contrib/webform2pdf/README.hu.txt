Telepítési útmutató webform2pdf modulhoz.

0. A modul licensze:
  GNU GPL v2.0

1. A program használatához szükséges szoftverek a telepítés sorrendjében:
- Drupal 7.x, letölthető: http://drupal.org/project/drupal címről.
- A webform Drupal modul, letölthető: http://drupal.org/project/webform címről.
- A webform2pdf Drupal modul, letölthető: http://drupal.org/project/webform2pdf címről.
- TCPDF pdf generáló könyvtár, letölthető: http://www.tcpdf.org/ címről.

2. Telepítés:
  2.1 Csomagoljuk ki a modult:
    $ tar -xvvzf webform2pdf-7.x-*.tar.gz

  2.2 Másoljuk a Drupal modul könyvtárába.

  2.3 Ezután csomagoljuk ki a TCPDF-et is:
    $ unzip tcpdf_*.zip

  2.4 A létrejött tcpdf könyvtárat másoljuk a sites/all/libraries könyvtárába.

  2.5 Lépjünk be a Drupalba adminisztrátorként es kapcsoljuk be (?q=admin/modules)
      a webform2pdf modult.

3. Első lépések.
  3.1 Az általános beállítások a ?q=admin/settings/webform2pdf oldalon találhatók.

  3.2 Hozzunk létre egy Űrlapot (vagy keressünk egy meglévőt) a webform modul
      segítségével.

  3.3 A űrlap menüjében található egyik almenü 'PDF készítés'.
      Itt engedélyezzük a PDF készítést, ezután megjelennek az elkészülő
      PDF beállítási lehetőségei.
