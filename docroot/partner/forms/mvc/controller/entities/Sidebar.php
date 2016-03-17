<?php

/**
 * Sidebar.php
 * Controller for the sidebar
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Sidebar extends Controller implements IController
{
    /**
     * Class controller
     *
     * @param bool $directOutput
     */
    public function __construct($directOutput = false)
    {
        $this->directOutput = $directOutput;
    }

    /**
     * Retrieve the class name
     * @return string
     */
    public static function getName()
    {
        return strtolower(__CLASS__);
    }

    /**
     * Execute the controller
     */
    public function execute()
    {
        $validatedSections = $this->validateSections();
        $params            = Parameters::getInstance();
        $renderer          = new Renderer('sidebar', false);
        $renderer->setViewPath($params->get('viewEntitiesPath'));
        $contentArray = array(
            'appurl'             => APP_URL . '?route=' . $params->get('route'),
            'appurlsidebar'      => APP_URL,
            'title'              => $params->get('title'),
            'sections'           => $this->getSections(),
            'currentRoute'      => $params->get('route'),
            'session_id'         => $params->getUrlParamValue('session_id'),
            'partner_type'       => $params->getUrlParamValue('partner_type'),
            'locked'             => $params->getUrlParamValue('locked'),
            'mf'                 => $params->getUrlParamValue('maintenance_mode'),
            'graceperiod'        => $params->getUrlParamValue('graceperiod'),
            'sections_validated' => $validatedSections,
            'category'           => $params->getUrlParamValue('entity'),
        );
        if(isset($_SESSION['returnCode'])){
            $contentArray['returnCode'] = $_SESSION['returnCode'];
        }
        //Vaciamos la variable returnCode para mostrar el dialog una núnica vez.
        $_SESSION['returnCode'] = '';
        $content      = $renderer->render($contentArray);
        if ($this->directOutput) {
            print $content;
        } else {
            return $content;
        }

    }

    /**
     * @return bool
     *
     * @throws \OshException
     */
    private function validateSections()
    {
        $params        = Parameters::getInstance();
        $originalRoute = $params->get('route');
        $entities      = false;
        if ($bundleData = File::read(APP_ROOT . $params->get('bundlesPath') . $params->get('defaultBundle'))) {
            if ($bundle = json_decode($bundleData, true)) {
                $entities = (isset($bundle['entities'])) ? $bundle['entities'] : false;
            }
        }
        if (! $entities) {
            throw new OshException('bad_config', 500);
        }
        
        $sections = $params->get('sections_validated');
        foreach ($entities as $entity) {
            $model = new Model(strtolower($params->getUrlParamValue('entity') . '_' . ucfirst($entity)));
            $params->set('route', $entity);
            if ($sessionID = $params->getUrlParamValue('session_id')) {
                $params->setUrlParamValue('session_id', $sessionID);
            }
            if ($mf = $params->get('maintenance_mode')) {
                $params->setUrlParamValue('maintenance_mode', $mf);
            }
            $model->load($sessionID);
            $attributes = $model->getAttributes();
            $aboutyourorgsection = false;
            $gencontactinfsection = false;
            $aboutyourceosection = false;
            $aboutyourrepsection = false;
            $supportforcampaignsection = false;
            $yourcampaignpledgesection = false;
            $tobecomeapartnersection = false;
            $primarycontactsection = false;

            foreach ($attributes as $name => &$attribute) {
                if($params->getUrlParamValue('partner_type') == 'current'){
                    if($name == "osh_primarycontactsection" && $attribute->getValue()){
                        $primarycontactsection = true;
                    }elseif($name == "osh_tobecomeapartnersection" && $attribute->getValue()){
                        $tobecomeapartnersection = true;
                    }elseif($name == "osh_supportforcampaignsection" && $attribute->getValue()){
                        $supportforcampaignsection = true;
                    }elseif($name == "osh_aboutyourceosection" && $attribute->getValue()){
                        $aboutyourceosection = true;
                    }elseif($name == "osh_yourcampaignpledgesection" && $attribute->getValue()){
                        $yourcampaignpledgesection = true;
                    }elseif($name == "osh_aboutyourorgsection" && $attribute->getValue()){
                        $aboutyourorgsection = true;
                    }elseif($name == "osh_gencontactinfsection" && $attribute->getValue()){
                        $gencontactinfsection = true;
                    }elseif($name == "osh_aboutyourrepsection" && $attribute->getValue()){
                        $aboutyourrepsection = true;
                    }
                }
            }
            foreach ($attributes as $name => &$attribute) {
                if($params->getUrlParamValue('partner_type') == 'current' && $name == 'contact_osh_confirm_mainemail'){
                    continue;
                }
                $section = $attribute->getSection();
                if (! empty($section) && isset($sections[$section])) {
                    $validation = $attribute->getValidator();
                    if (! empty($validation)) {
                        if ((is_array($validation) && array_search('not_null', $validation))
                            || ((! is_array($validation)) && (strval($validation) === strval('not_null')))) {
                            $sections[$section] &= $model->validate($attribute->getName());
                            if($sections[$section] && $params->getUrlParamValue('partner_type') == 'current'){
                                if($section == "ORGANISATION" && !$aboutyourorgsection){
                                    $sections[$section] = 0;
                                }elseif($section == "GENERAL_INFORMATION" && !$gencontactinfsection){
                                    $sections[$section] = 0;
                                }elseif(($section == "CEO" || $section == "CHIEF") && !$aboutyourceosection){
                                    $sections[$section] = 0;
                                }elseif($section == "BECOME" && !$tobecomeapartnersection){
                                    $sections[$section] = 0;
                                }elseif($section == "INVOLVEMENT" && !$supportforcampaignsection){
                                    $sections[$section] = 0;
                                }elseif($section == "PLEDGE" && !$yourcampaignpledgesection){
                                    $sections[$section] = 0;
                                }elseif($section == "PRIMARY_CONTACT" && !$primarycontactsection){
                                    $sections[$section] = 0;
                                }elseif($section == "OSH" && !$aboutyourrepsection){
                                    $sections[$section] = 0;
                                }
                            }
                        }
                    }
                    //Workaround OSH section -> Not have required fields
                    if($sections[$section] && $params->getUrlParamValue('partner_type') == 'current' && $section == "OSH" && !$aboutyourrepsection){
                                    $sections[$section] = 0;
                                }
                }
            }
        }
        $params->set('route', $originalRoute);

        return $sections;
    }

    /**
     * Retrieve the current sections
     * @return array
     */
    private function getSections()
    {
        $params       = Parameters::getInstance();
        $entity       = $params->getUrlParamValue('entity');
        $routes       = $params->get('routes');
        $partnertype = $params->getUrlParamValue('entity');
        if($partnertype == 'fop'){
            unset($routes['involvement']);
        }
        $entitiesPath = $params->get('entitiesPath');
        foreach ($routes as $route => $routeData) {
            $entityFile = APP_ROOT . $entitiesPath . $entity . '_' . $route;
            if ($content = File::read($entityFile)) {
                $content = json_decode($content, true);
                $content = isset($content['sections']) ? $content['sections'] : '';
                if($partnertype == 'fop' && isset($content['title'])){
                    if($content['title'] == "3. Contact information"){
                        $content['title'] = "2. Contact information";
                    }
                }
                if ($content && isset($content['title']) && isset($content['sections'])) {
                    $sections[] = array(
                        'title'    => $content['title'],
                        'route'    => $route,
                        'sections' => $params->getUrlParamValue('maintenance_mode') && is_array($content['sections_mf']) ? $content['sections_mf'] : $content['sections'],
                    );
                }
            }
        }

        return $sections;
    }
}