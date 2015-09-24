<?php

/**
 * @file
 *   Webform2pdf module W2PDF object class.
 */
include_once(libraries_get_path('tcpdf') . '/tcpdf.php');

class W2PDF extends TCPDF {

  /**
   * @var Header left, right image logo.
   * @access protected
   */
  protected $header_logo = array();

  /**
   * @var Header left, right image logo width in mm.
   * @access protected
   */
  protected $header_logo_size = array();

  /**
   * @var align string to print on document header.
   * @access protected
   */
  protected $header_string_align = array();

  /**
   * @var Footer left, right image logo.
   * @access protected
   */
  protected $footer_logo = array();

  /**
   * @var Footer left, right image logo width in mm.
   * @access protected
   */
  protected $footer_logo_size = array();

  /**
   * @var align string to print on document footer.
   * @access protected
   */
  protected $footer_string_align = array();

  /**
   * path to background image
   * @var string
   */
  protected $background = NULL;

  /**
   * Set header data.
   * @param array $ln header left, right image logo
   * @param array $lw header left, right image logo width in mm
   * @param string $hs string to print on document header
   * @param string $hsa align string to print on document header
   */
  public function setHeaderData($ln = array(), $ls = array(), $hs = '', $hsa = '', $tc=array(0,0,0), $lc=array(0,0,0), $background = NULL) {
    $this->header_logo = $ln;
    $this->header_logo_size = $ls;
    $this->header_string = $hs;
    $this->header_string_align = $hsa;
    $this->header_text_color = $tc;
    $this->header_line_color = $lc;
    $this->background = $background;
  }

  /**
   * Returns header data:
   * @return array()
   * @since 4.0.012 (2008-07-24)
   */
  public function getHeaderData() {
    $ret = array();
    $ret['logo'] = $this->header_logo;
    $ret['logo_size'] = $this->header_logo_size;
    $ret['string'] = $this->header_string;
    $ret['align'] = $this->header_string_align;
    $ret['background'] = $this->background;
    return $ret;
  }

  /**
   * Set footer data.
   * @param array $ln footer left, right image logo
   * @param array $ls footer left, right image logo width, height in mm
   * @param string $hs string to print on document footer
   * @param string $hsa align string to print on document footer
   */
  public function setFooterData($ln=array(), $ls=array(), $hs='', $hsa='') {
    $this->footer_logo = $ln;
    $this->footer_logo_size = $ls;
    $this->footer_string = $hs;
    $this->footer_string_align = $hsa;
  }

  /**
   * Returns footer data:
   * @return array()
   * @since 4.0.012 (2008-07-24)
   */
  public function getFooterData() {
    $ret = array();
    $ret['logo'] = $this->footer_logo;
    $ret['logo_size'] = $this->footer_logo_size;
    $ret['string'] = $this->footer_string;
    $ret['align'] = $this->footer_string_align;
    return $ret;
  }

  /**
   * This method is used to render the page header.
   * It is automatically called by AddPage() and could be overwritten in your own inherited class.
   */
  public function Header() {
    $ormargins = $this->getOriginalMargins();
    $headerfont = $this->getHeaderFont();
    $headerdata = $this->getHeaderData();

    $imgy['left'] = $imgy['right'] = $this->GetY();
    $header_w = 0;

    $empty_header = 1;

    if ($headerdata['background']) {
       // get the current page break margin
      $bMargin = $this->getBreakMargin();
       // get current auto-page-break mode
      $auto_page_break = $this->AutoPageBreak;
       // disable auto-page-break
      $this->SetAutoPageBreak(false, 0);
       //Image($file, $x='', $y='', $w=0, $h=0, $type='', $link='', $align='', $resize=false, $dpi=300, $palign='', $ismask=false, $imgmask=false, $border=0, $fitbox=false, $hidden=false, $fitonpage=false, $alt=false, $altimgs=array())
      $this->Image($headerdata['background'], 0, 0, $this->w, $this->h, '', '', '', false, 300, '', false, false, 0);
       // restore auto-page-break status
      $this->SetAutoPageBreak($auto_page_break, $bMargin);
       // set the starting point for the page content
      $this->setPageMark();
    }

    if ( (!empty($headerdata['logo']['left'])) && (!empty($headerdata['logo_size']['left']['w'])) ) {
      if (($headerdata['logo']['left']) AND ($headerdata['logo']['left'] != K_BLANK_IMAGE)) {
        $this->Image($headerdata['logo']['left'], $this->GetX(), $this->getHeaderMargin(), $headerdata['logo_size']['left']['w']);
        $imgy['left'] = $this->getImageRBY();
        $empty_header = 0;
      }
    }

    if (($headerdata['logo']['right']) AND ($headerdata['logo']['right'] != K_BLANK_IMAGE)) {
      $this->Image($headerdata['logo']['right'], ($this->getPageWidth() - $ormargins['right'] - $headerdata['logo_size']['right']['w']), $this->getHeaderMargin(), $headerdata['logo_size']['right']['w']);

      $header_w = $this->getPageWidth() - $ormargins['left'] - $ormargins['right'] - ($headerdata['logo_size']['right']['w'] * 1.1);
      if ( (!empty($headerdata['logo']['left'])) && (!empty($headerdata['logo_size']['left']['w'])) ) {
        $header_w -= $headerdata['logo_size']['left']['w'] * 1.1;
      }
      $imgy['right'] = $this->getImageRBY();
      $empty_header = 0;
    }

    $cell_height = round(($this->getCellHeightRatio() * $headerfont[2]) / $this->getScaleFactor(), 2);
    // set starting margin for text data cell
    if ($this->getRTL()) {
      $header_x = $ormargins['right'] + ($headerdata['logo_size']['right']['w'] * 1.1);
    }
    else {
      $header_x = $ormargins['left'] + ($headerdata['logo_size']['left']['w'] * 1.1);
    }

    $this->SetTextColor(0, 0, 0);

    // header html string
    $this->SetFont($headerfont[0], $headerfont[1], $headerfont[2]);
    $this->SetX($header_x);

    if ( !empty($headerdata['string']) ) {
      $empty_header = 0;
    }

    $this->writeHTMLCell($header_w, $cell_height, '', '', $headerdata['string'], 0, 1, 0, TRUE, $headerdata['align']);
    // print an ending header line
    $this->SetLineStyle(array('width' => 0.85 / $this->getScaleFactor(), 'cap' => 'butt', 'join' => 'miter', 'dash' => 0, 'color' => array(0, 0, 0)));
    $this->SetY(1 + max($imgy['left'], $this->GetY()));
    $this->SetY(1 + max($imgy['right'], $this->GetY()));
    if ($this->getRTL()) {
      $this->SetX($ormargins['right']);
    }
    else {
      $this->SetX($ormargins['left']);
    }

    if ( !$empty_header ) {
      $this->Cell(0, 0, '', 'T', 0, 'C');
    }
    $this->SetTopMargin($this->GetY()+1);
  }

  /**
   * This method is used to render the page footer.
   * It is automatically called by AddPage() and could be overwritten in your own inherited class.
   */
  public function Footer() {
    $ormargins = $this->getOriginalMargins();
    $footerfont = $this->getFooterFont();
    $footerdata = $this->getFooterData();
    $imgy['left'] = $imgy['right'] = $this->GetY();
    $footer_w = 0;

    $empty_footer = 1;

//    $footer_height = $cell_height = count( explode("\n", $footerdata['string']) ) * round(($this->getCellHeightRatio() * $footerfont[2]) / $this->getScaleFactor(), 2);
    $cell_height = 18;
    if ( (!empty($footerdata['logo_size']['left']['h'])) || (!empty($footerdata['logo_size']['right']['h'])) ) {
//      $footer_height = max($cell_height, $footerdata['logo_size']['left']['h'], $footerdata['logo_size']['right']['h']);
      $this->SetY($this->GetY() - $cell_height );
    }
    else {
      $this->SetY($this->GetY() -  $cell_height);
    }

    if ( (!empty($footerdata['logo']['left'])) && (!empty($footerdata['logo_size']['left']['w'])) ) {
      if (($footerdata['logo']['left']) AND ($footerdata['logo']['left'] != K_BLANK_IMAGE)) {
        $this->Image($footerdata['logo']['left'], $this->GetX(), $this->GetY(), $footerdata['logo_size']['left']['w']);
        $imgy['left'] = $this->getImageRBY();
        $empty_footer = 0;
      }
    }

    if (($footerdata['logo']['right']) AND ($footerdata['logo']['right'] != K_BLANK_IMAGE)) {
      $this->Image($footerdata['logo']['right'], ($this->getPageWidth() - $ormargins['right'] - $footerdata['logo_size']['right']['w']), $this->GetY(), $footerdata['logo_size']['right']['w']);

      $footer_w = $this->getPageWidth() - $ormargins['left'] - $ormargins['right'] - ($footerdata['logo_size']['right']['w'] * 1.1);
      if ( (!empty($footerdata['logo']['left'])) && (!empty($footerdata['logo_size']['left']['w'])) ) {
        $footer_w -= $footerdata['logo_size']['left']['w'] * 1.1;
      }
      $imgy['right'] = $this->getImageRBY();
      $empty_footer = 0;
    }

    $this->SetTextColor(0, 0, 0);
    $this->SetY($this->GetY() - 1);

    // set starting margin for text data cell
    if ($this->getRTL()) {
      $footer_x = $ormargins['right'] + ($footerdata['logo_size']['right']['w'] * 1.1);
    }
    else {
      $footer_x = $ormargins['left'] + ($footerdata['logo_size']['left']['w'] * 1.1);
    }

    $this->SetX($footer_x);

    $line_width = 0.85 / $this->getScaleFactor();

    // print an ending footer line
    $this->SetLineStyle(array('width' => $line_width, 'cap' => 'butt', 'join' => 'miter', 'dash' => 0, 'color' => array(0, 0, 0)));

    // footer html string
    $page_var = array("%pagenumber" => $this->PageNoFormatted(), "%totalpage" => $this->getAliasNbPages());
    $footerdata['string'] = strtr($footerdata['string'], $page_var);
    $this->SetFont($footerfont[0], $footerfont[1], $footerfont[2]);

    if ( !empty($footerdata['string']) ) {
      $empty_footer = 0;
    }

    $this->writeHTMLCell($footer_w, $cell_height, '', '', $footerdata['string'], 0, 0, 0, TRUE, $footerdata['align']);

    if ($this->getRTL()) {
      $this->SetX($ormargins['right']);
    }
    else {
      $this->SetX($ormargins['left']);
    }
    if ( !$empty_footer ) {
      $this->Cell(0, 0, '', 'T', 0, 'C');
    }
  }
}
