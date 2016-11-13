<?php

/**
 * Controller.php
 * Abstract class for controllers
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
abstract class Controller {

    /**
     * @var Model object
     */
    protected $model;

    /**
     * @var Direct output or return
     */
    protected $directOutput;

    /**
     * Execute an action defined in the specific controller
     */
    public function executeAction() {
        $params = Parameters::getInstance();
        $action = $params->get('action');
        if (method_exists($this, $action)) {
            $this->$action();
        }
    }

    /**
     * Execute the controller
     */
    public function execute() {
        // Load the entity
        $this->load();
        $params = Parameters::getInstance();
        // Build the progressbar and the sidebar
        $sidebar = new Sidebar(false);
        $sidebarContent = $sidebar->execute();
        $progressbar = new Progressbar(false);
        $progressbarContent = $progressbar->execute();
        // Build the form
        $route = $params->get('route');
        $statusCode  = $params->get('statuscode');
        $sent        = intval($params->get('cdb')['sent']);
        if ($statusCode != $sent){
            //Insertamos una variable para mostrar el check del main contact change.
            $_SESSION['mainContactChangeCheck'] = true;
        }
        $submitText = isset($params->get('routes')[$route]['submitText']) ? $params->get('routes')[$route]['submitText'] : 'Next';
        $isPrintable = $this->isPrintable();
        $renderer = new Renderer($this->getEntityName());
        $renderer->setViewPath($params->get('viewEntitiesPath'));
        $urlBase = APP_URL;
        $cdbMap = $this->model->getCdbMap();
        $cdb = CDB::getInstance($cdbMap);
        // CRG - 29.10.2015
        $attributes = $this->model->getAttributes();
        foreach ($attributes as $kAttr => $attr) {
            if($kAttr == 'company_osh_orgnameAux' && $attr->getValue()!=""){
                $this->model->set($attr->getName(), $attr->getValue());
            }
            $type = $attr->getType();
            $name = $attr->getName();
            if ($type == Attribute::TYPE_DROPDOWN || $type == Attribute::TYPE_DROPDOWN_MULTIPLE) {
                $value = $cdb->getDropdown($name);
                $attr->setValue($value);
            }
        }
        //
        $contentArray = array(
            'appurl' => APP_URL . '?route=' . $params->get('route'),
            'urlBase' => APP_URL,
            'title' => $params->get('title'),
            'nonce' => $params->get('nonce'),
            'sidebar' => $sidebarContent,
            'progressbar' => $progressbarContent,
            'attributes' => $this->transformAttributes(),
            'session_id' => $params->getUrlParamValue('session_id'),
            'mf' => $params->get('maintenance_mode'),
            'partner_type' => $params->getUrlParamValue('partner_type'),
            'mainContactChangeCheck' => $this->maincontactChange(),
            'submit_text' => $submitText,
            'printable' => $isPrintable,
            'HelpMessage' => $this->helpMessage(),
            'show_print_version' => $params->get('print'),
            'show_pdf_version' => $params->get('pdf'),
            'locked' => $params->getUrlParamValue('locked'),
            'actionType' => $params->get('actionType'),
            'disabled' => '',
            'fieldsValidatingDialog' => $this->fieldsValidation(),
        );
        // PDF version
        if ($isPrintable) {
            $route = $params->get('route');
            $params->set('route', 'MaintenanceForm');
            $maintenanceForm = new MaintenanceForm(false);
            $content = $maintenanceForm->execute();
            $params->set('route', $route);
        
//            $content = $renderer->render($contentArray);
        } else {
            // Content rendering
            $content = $renderer->render($contentArray);
        }
        if ($this->directOutput) {
            print $content;
        } else {
            return $content;
        }
    }
    
    public function helpMessage() {
        $params = Parameters::getInstance();
        if($params->get('action') == 'printable'){
            return "print";
        }else{
            return "";
        }
    }
    public function fieldsValidation(){
        if(isset($_SESSION['fieldsValidatingDialog']) && $_SESSION['fieldsValidatingDialog'] && !isset($_SESSION['ValidatingDialogHidden'])){
            unset($_SESSION['fieldsValidatingDialog']);
            $_SESSION['ValidatingDialogHidden']=true;
            return true;
        }else{
            return false;
        }
    }
    

    /**
     * Load an entity
     */
    public function load() {
        $params = Parameters::getInstance();
        $session = Session::getInstance();
        if ($sessionID = $params->getUrlParamValue('session_id')) {
            $params->setUrlParamValue('session_id', $sessionID);
            if (isset($_REQUEST['session_id'])) {
                $session->setAttribute(Constants::SESSIONID_NAME, $sessionID);
            }
        }

        if ($mf = $params->get('maintenance_mode')) {
            $params->setUrlParamValue('maintenance_mode', $mf);
        }
        $this->model->load($sessionID);
    }

    /**
     * Determine whether the form is in printable mode or not
     * @return bool|string
     */
    protected function isPrintable() {
        $params = Parameters::getInstance();
        if ($params->get('action') == 'pdf' || $params->get('action') == 'printable') {
            $ret = ($params->get('action') == 'pdf') ? 'pdf' : 'printable';
        } else {
            $ret = false;
        }
        return $ret;
    }

    /**
     * Transform the attributes depending on its type of control
     * @return array
     */
    protected function transformAttributes() {
        $transformedAttributes = array();
        $params = Parameters::getInstance();
        $attributes = $this->model->getAttributes();
        $nonce = $params->get('nonce');
        foreach ($attributes as $id => $attribute) {
            if($params->get('action') == 'printable' && $attribute->getName() == 'contact_osh_captcha'){
                continue;
            }
            if ($attribute->getName()) {
                // Render the attribute widget
                //$disabled = $params->getUrlParamValue('partner_type') == 'current' ? 'disabled' : '';
                $disabled = $params->getUrlParamValue('locked') ? 'disabled' : '';
                if (is_array(($attribute->getValidator()))) {
                    foreach ($attribute->getValidator() as $validator) {
                        $required = ($validator == Validator::VALIDATION_NOTNULL) ? 'required' : '';
                    }
                } else {
                    $required = ($attribute->getValidator() == Validator::VALIDATION_NOTNULL) ? 'required' : '';
                }
                if ($attribute->getType() == Attribute::TYPE_RADIO) {
                    $radioValue = $attribute->getValue();
                    if(empty($radioValue)){
                        $attribute->setValue('No');
                    }else if ($radioValue == 1 || $radioValue == "1"){
                        $attribute->setValue('Yes');
                    }
                }
                if ($attribute->getType() == Attribute::TYPE_DROPDOWN_MULTIPLE) {
                    $data = $attribute->getValue();
                    foreach ($data as $countryKey => $countryValue) {
                        if (is_array($attribute->getSelectedValues())) {
                            $selected = in_array($countryValue, $attribute->getSelectedValues());
                        } else {
                            $selected = $countryValue == $attribute->getSelectedValues();
                        }
                        $countries[] = array(
                            'id' => $countryKey,
                            'name' => $countryValue,
                            'selected' => $selected,
                        );
                    }
                    $countriesProcessed = array('values' => $countries);
                    $attribute->setValue($countriesProcessed);
                }
                if ($attribute->getType() == Attribute::TYPE_IMAGE) {
                    $valueArray = $attribute->getValue();
                    if (isset($valueArray["content"])) {
                        $value = $valueArray["content"];
                    }
                } else {
                    $value = $attribute->getValue();
                }

                $attributeContentArray = array(
                    'appurl' => APP_URL,
                    'nonce' => $nonce,
                    'fieldName' => $attribute->getName(),
                    'fieldLabel' => $attribute->getLabel(),
                    'fieldPlaceholder' => $attribute->getPlaceholder(),
                    'fieldPublicProfile' => $attribute->getPublicProfile(),
                    'fieldHelpText' => $attribute->getHelpText(),
                    'fieldHelpTextImage' => $attribute->getHelpTextImageLoaded(),
                    'fieldSection' => $attribute->getSection(),
                    'fieldValue' => $attribute->getValue(),
                    'selectedValue' => $attribute->getSelectedValues(),
                    'required' => $required,
                    'locked' => $params->getUrlParamValue('locked'),
                    'disabled' => $disabled,
                );

                if ($attribute->getType() == Attribute::TYPE_IMAGE) {
                    $valueImage = null;
                    if(null !== $attribute->getValue() && isset($attribute->getValue()[0])){
                        $valueImage = $attribute->getValue()[0];
                    }
                    if (isset($valueImage)) {
                        $imageContent = $valueImage;
                        $imageContent = str_replace(array("\\"), "/", $imageContent);
                        $attributeContentArray["fieldValue"] = array("mime" => "", "content" => $imageContent);
                    }
                }
                $attributeRendered = $this->renderWidget($attribute->getType(), $attributeContentArray);
                $transformedAttributes[$attribute->getName()] = $attributeRendered;
            }
        }
        return $transformedAttributes;
    }
    protected function maincontactChange() {
        if(isset($_SESSION['mainContactChangeCheck']) && $_SESSION['mainContactChangeCheck']){
            return true;
        }else{
            return "";
        }
    }

    /**
     * Render a widget
     * @param $view
     * @param $contentArray
     * @return string
     */
    private function renderWidget($view, $contentArray) {
        $params = Parameters::getInstance();
        if ($this->isPrintable()) {
            if ($view == 'image') {
                $contentArray['image'] = true;
            }
            $view = $params->get('printableTpl');
        }
        $renderer = new Renderer('', false);
        $renderer->setViewPath($params->get('widgetsPath'));
        $renderer->setView($view);
        $content = $renderer->render($contentArray);
        return $content;
    }

    /**
     * Save action
     */
    public function save() {
        $this->saveToSession();
        // Perform the send to CDB
        $params = Parameters::getInstance();
        if (!$params->get('print') && !$params->get('pdf')) {
            $this->send(true);
        }
    }

    /**
     * Save the data into session
     */
    private function saveToSession() {
        $this->load();
        $params = Parameters::getInstance();
        $attributes = $this->model->getAttributes();
        if ($attributes) {
            foreach ($attributes as $attribute) {
                $name = $attribute->getName();
                if ($value = $params->get($name)) {
                    if ($attribute->getType() == Attribute::TYPE_DROPDOWN ||
                            $attribute->getType() == Attribute::TYPE_DROPDOWN_MULTIPLE
                    ) {
                        if (intval($attribute->getSelectedValues()) === -1) {
                            $attribute->setSelectedValues(null);
                        } else {
                            $attribute->setSelectedValues($value);
                        }
                    } else {
                        $attribute->setValue($value);
                    }
                    $this->model->setWholeAttribute($attribute);
                }
            }
            $this->model->saveSession();
        }
    }

    /**
     * Save and Send action
     * @param bool $save
     * @param bool $updateMF
     */
    public function send($save = false, $updateMF = false) {
        $params = Parameters::getInstance();
        $valorParam = $params->get('actionType');
        if (!$save && !($valorParam === 'submit')) {
            $this->saveToSession();
        }


        if ($save || $valorParam == 'submit') {
            if ($bundleData = File::read(APP_ROOT . $params->get('bundlesPath') . $params->get('defaultBundle'))) {
                if ($bundle = json_decode($bundleData, true)) {
                    $entities = (isset($bundle['entities'])) ? $bundle['entities'] : false;
                    if ($entities) {
                        $mapping = array();
                        $currentRoute = $params->get('route');
                        $currentModel = $this->model;
                        foreach ($entities as $entity) {
                            $this->model = new Model(strtolower($params->getUrlParamValue('entity') . '_' . ucfirst($entity)));
                            if ($updateMF) {
                                $this->model->setCdbMap(true);
                            } else {
                                $this->model->setCdbMap(false);
                            }
                            $params->set('route', $entity);
                            $session = Session::getInstance();

                            /*
                             * POngo el if porque en el NEW pasa por el load carga los attributes de la sesi�n
                             *  y pone los datos en la sesi�n,eso esta mal)
                             */
//                            
//                            
                            //Resolución incidencia redes sociales. Al ser campos dinámicos, forzamos su almacenamiento en sesión, ya que el load pisaba los cambios.
//                            foreach ($this->model->getAttributes() as $atributo) {
//                                if($atributo->getName()=="company_osh_facebookprofile" || $atributo->getName()=="company_osh_twitterprofile"  || $atributo->getName()=="company_osh_pinterestprofile"  ||
//                                   $atributo->getName()=="company_osh_youtubeprofile"  || $atributo->getName()=="company_osh_linkedinprofile" || $atributo->getName()=="company_osh_slideshareprofile"){
//                                        $session->setAttribute($atributo->getName(), $atributo->getValue());
//                                }
//                            }
                            foreach ($this->model->getAttributes() as $atributo) {
                                if(strpos($atributo->getName(), 'otherus') !== false || strpos($atributo->getName(), 'publication') !== false ||
                                        strpos($atributo->getName(), 'readership') !== false){
                                        $session->setAttribute($atributo->getName(), $params->get($atributo->getName()));
                                }
                                if(isset($_SESSION['mf']) && $_SESSION['mf']){
                                    if(strpos($atributo->getName(), 'profile') !== false){
                                        $name = $atributo->getName();
                                        if (isset($_POST[$name])){
                                            $value = $_POST[$name];
                                        }
                                        if(isset($value)){
                                            $session->setAttribute($name, $value);
                                            $params->set($name, $value, true);
                                        }
                                    }
                                }
                            }
                            
                            $this->saveToSession();
                            $attributes = $this->model->getAttributes();
                            foreach ($attributes as $attr) {
                                $cdbName = $this->model->getTranslation($attr);
                                if ($cdbName) {
                                    if ($attr->getType() == Attribute::TYPE_IMAGE) {
                                        $attr->setValue($session->getAttribute($attr->getName()));
                                        //(CRG - # Envio de imagenes )
                                        $image = $attr->getValue();
                                        
                                        if (isset($image["content"]) && ($image["content"] != null || $image["content"] != "")) {
                                           // $routeImage = Model::uploadPhoto($image["content"]); //Las subimos
                                            $mapping[$cdbName] = $image["content"];
                                        } else {
                                            $mapping[$cdbName] = "";
                                        }
                                        unset($image);
                                        //(/CRG - # Envio de imagenes)
                                    } else if ($attr->getType() == Attribute::TYPE_RADIO ||
                                            $attr->getType() == Attribute::TYPE_CHECKBOX 
                                            || $attr->getType() == Attribute::TYPE_CONTACTCHANGE
                                    ) {
                                        $mapping[$cdbName] = (strtolower($attr->getValue()) == 'on' || strtolower($attr->getValue()) == 'yes') ? 'true' : 'false';
                                    } elseif ($attr->getType() == Attribute::TYPE_DROPDOWN || $attr->getType() == Attribute::TYPE_DROPDOWN_MULTIPLE) {
                                        $mapping[$cdbName] = $attr->getSelectedValues();

                                        if (($attr->getType() == Attribute::TYPE_DROPDOWN)) {
                                            if (empty($attr->getSelectedValues())) {

//                                                $attr->setSelectedValues(0);
//                                                $v = $attr->getSelectedValues();
//                                                $mapping[$cdbName] = $v;
                                            }
                                        }
                                    } else {
                                        //Envío de checks de secciones en el formato establecido.
                                        if (strpos($cdbName, 'section') !== false) {
                                            if($attr->getValue() == ""){
                                                $mapping[$cdbName] = "false";
                                            }else if ($attr->getValue() == "0"){
                                                $mapping[$cdbName] = "false";
                                            }else if ($attr->getValue() == "1"){
                                                $mapping[$cdbName] = "true";
                                            }else{
                                                $mapping[$cdbName] = $attr->getValue();
                                            }
                                        }else{
                                            $mapping[$cdbName] = $attr->getValue();
                                            
                                        }
                                    }
                                }
//                                if ($this->isOtherUserField($attr->getName())){
//                                    $mapping[$attr->getName()] = $attr->getValue();
//                                }
                            }
                        }

                        //$params->set('route', $currentRoute);
                        $this->model = $currentModel;
                        $type = $save || $params->get('actionType') == 'next' ? 'save' : 'submit';
                        $paramRequest = $this->getBuiltURL($mapping, $type);
                        $this->model->saveToCDB($paramRequest);
                    }
                }
            }
        }
        if (!$save) {
            if(isset($_SESSION['mf']) && $_SESSION['mf']== true){
                $_SESSION['submitted'] = true;
            }
            $route = $params->get('route');
            $nextRoute = isset($params->get('routes')[$route]['next']) ? $params->get('routes')[$route]['next'] : '';
            if(isset($_SESSION['mf']) && $_SESSION['mf']== true){
                 header('Location: ' . APP_URL . '?route=' . $nextRoute . "&mf=true");
            }else{
                 header('Location: ' . APP_URL . '?route=' . $nextRoute);
            }
           
            exit;
        } else {
            $url = "$_SERVER[REQUEST_URI]";
            $start = strstr($url, '?');
            $nextRoute = strstr($start, '&', true);
            header('Location: ' . APP_URL . $nextRoute);
            exit;
        }
    }

    /**
     * Return the formed URL request data for the update method of CDB
     *  * @TODO: set the delimiter data in cdb.json and acces it generically through params:
     *      field delimiter: ','
     *      value delimiter: '|'
     *      enclosure start tag: '('
     *      enclosure end  tag: ')'
     *      fields delimiter: '&'
     *      etc
     *
     * @param array $fields
     * @param string $type
     *
     * @return array
     */
    protected function getBuiltURL(array $fields, $type) {
        $params = Parameters::getInstance();
        $updatedValues = '';
        $countries = '';
        $otherUsers1 = '';
        $otherUsers2 = '';
        $otherUsers3 = '';
        $otherUsers4 = '';
        $otherUsers5 = '';
        $normalValues = array();
        foreach ($fields as $key => $value) {
            // Envío del tipo de imagen
            if ($key == "osh_logoimage" && $value != "") {
                $keyLogoImageType = "osh_logotype";
                $valueLogoImageType = "png";
            }
            if ($key == "osh_ceoimage" && $value != "") {
                $keyCeoImageType = "osh_ceoimagetype";
                $valueCeoImageType = "png";
            }
            //Validamos si se han modificado las variqbles pledge o quote, dado que si estas variables han sido modificadas el mensaje en el 
            //congrats será diferente para los maintenance forms.
                if ($key == "osh_campaignpledge") {
                    if(isset($_SESSION['pledgeOld'])){
                        if($_SESSION['pledgeOld']!=$value){
                            $_SESSION['alertFieldModified'] = true;
                        }
                    }else if($value != ""){
                        $_SESSION['alertFieldModified'] = true;
                    }
                }
                if ($key == "osh_quoteonhwc") {
                    if(isset($_SESSION['quoteOld'])){
                        if($_SESSION['quoteOld']!=$value){
                            $_SESSION['alertFieldModified'] = true;
                        }
                    }else if($value != ""){
                        $_SESSION['alertFieldModified'] = true;
                    }
                }

                
            if (strpos($key, 'category') !== false || strpos($key, 'leads') !== false || $key == "contact_osh_mainemailAux" || $key == "company_osh_orgnameAux" || $key == "contact_osh_maincontactpersonfirstnameAux" || $key == "contact_osh_maincontactpersonlastnameAux") {
                // Don't send neither category and osh_leads field.
                continue;
                
            } elseif ($key == "returnPaises") {
                //          (/CRG - #157)
                // Countries of Activities dropdown

                if ((!empty($value)) && is_array($value)) {
                    $countries .= implode(',', array_keys($value));
                } else {
                    $countries = null;
                }
            } elseif (strpos($key, 'otheruser') === false && $key != 'fullname1' && $key != 'fullname2' && $key != 'fullname3' && $key != 'fullname4' && $key != 'fullname5') {
                //Normal fields
                if (isset($value)) {
                    if (isset($keyLogoImageType)){
                        $normalValues[$keyLogoImageType]  = $valueLogoImageType;
//                        $updatedValues .= '(' . $keyLogoImageType . '|' . $valueLogoImageType . '),';
                    }
                    if (isset($keyCeoImageType)){
                        $normalValues[$keyCeoImageType]  = $valueCeoImageType;
//                        $updatedValues .= '(' . $keyCeoImageType . '|' . $valueCeoImageType . '),';
                    }
                    
                    $value = str_replace("\"", "''", $value);
                    $normalValues[$key]  = $value ;
//                    $updatedValues .= '(' . $key . '|' . $value . '),';
                }
            } else {
                // Other Users
                 
                if($key === 'fullname1'){
                    $otherUsers1 .= '(' . str_replace(" ","+",$value) . '|';
                }else if($key === 'osh_otheruseremail1'){
                    $otherUsers1 .= $value . '|';
                }else if($key === 'osh_otheruserphone1'){
                    $otherUsers1 .= $value . ')';
                }else if($key === 'fullname2'){
                    $otherUsers2 .= '(' . str_replace(" ","+",$value) . '|';
                }else if($key === 'osh_otheruseremail2'){
                    $otherUsers2 .= $value . '|';
                }else if($key === 'osh_otheruserphone2'){
                    $otherUsers2 .= $value . ')';
                }else if($key === 'fullname3'){
                    $otherUsers3 .= '(' . str_replace(" ","+",$value) . '|';
                }else if($key === 'osh_otheruseremail3'){
                    $otherUsers3 .= $value . '|';
                }else if($key === 'osh_otheruserphone3'){
                    $otherUsers3 .= $value . ')';
                }else if($key === 'fullname4'){
                    $otherUsers4 .= '(' . str_replace(" ","+",$value) . '|';
                }else if($key === 'osh_otheruseremail4'){
                    $otherUsers4 .= $value . '|';
                }else if($key === 'osh_otheruserphone4'){
                    $otherUsers4 .= $value . ')';
                }else if($key === 'fullname5'){
                    $otherUsers5 .= '(' . str_replace(" ","+",$value) . '|';
                }else if($key === 'osh_otheruseremail5'){
                    $otherUsers5 .= $value . '|';
                }else if($key === 'osh_otheruserphone5'){
                    $otherUsers5 .= $value . ')';
                }
            }
        }
        //Desseteamos los valores antiguos de pledge y quote
        if(isset($_SESSION['alertFieldModified']) && $_SESSION['alertFieldModified']){
                    unset($_SESSION['quoteOld']);
                    unset($_SESSION['pledgeOld']);
                }
        // $result .= ! empty ($updatedValues) ? 'id=' . $params->get('session_id') . '&option=SUBMIT&fields=' . substr($updatedValues, 0, -1) : '';
        //        $result = ! empty ($otherUsers) ? $result . 'otherusers=' . substr($updatedValues, 0, -1) : substr($result, 0, -1);
        $result = array(
            'id' => $params->get('session_id'),
            'fields' => $normalValues
//            'fields' => substr($updatedValues, 0, -1)
        );

        if ($params->getUrlParamValue('no_session_id')) {
            unset($result['id']);
        }
        //          (CRG - #157 - Comento el if (!empty($countries)) porque está rellenando returnPaises como un fields,cuando debe ir fuera)
        //        if (!empty($countries)) {
        $result['paises'] = $countries;
        $result['otherusers1'] = $otherUsers1;
        $result['otherusers2'] = $otherUsers2;
        $result['otherusers3'] = $otherUsers3;
        $result['otherusers4'] = $otherUsers4;
        $result['otherusers5'] = $otherUsers5;
        //        }
        //          (/CRG - #157 )
        if (!$params->getUrlParamValue('maintenance_mode')) {
            $result['option'] = ($type == 'submit') ? 'SUBMIT' : 'SAVE';
        } else {
            $result['option'] = 'SUBMIT';
        }

        return $result;
    }

    /**
     * Function validateAttribute
     *
     * @return bool
     */
    protected function validateAttribute() {
        $ret = true;
        if ($this->model) {
            $param = Parameters::getInstance();
            $attribute = $param->get('attribute');
            $value = $param->get('value');
            $this->model->set($attribute, $value);
            $ret = $this->model->validate($attribute);
        }
        if ($param->get('ajax')) {
            $messageBus = MessageBus::getInstance();
            $response = array(
                'status' => $ret,
                'id' => $attribute,
                'message' => $messageBus->getMessage($attribute),
            );
            print json_encode($response);
            die;
        } else {
            return $ret;
        }
    }

    /**
     * Download a PDF file
     * @param string $content
     * @param string $controller
     */
    protected function downloadPdf($content = '', $controller = '') {
        if (!empty($content)) {
            $params = Parameters::getInstance();
            $pdf = new Pdf();
            $path = $pdf->render($content);
            File::download($params->get('pdfFilename') . '-' . date('d-m-Y_H-i'), $path, 'application/pdf');
            die;
        }
    }

    /**
     * Get Value based on type.
     *
     * @param Attribute $attribute
     * @return array|bool|null|string
     */
    protected function getValue(Attribute $attribute) {
        switch ($attribute->getType()) {
            case 'dropdown':
            case 'dropdown_multiple':
                return $attribute->getSelectedValues();
                break;
            case 'radio':
                return $attribute->getValue() === 'Yes' ? true : $attribute->getValue() === 'No' ? false : null;
                break;
            case 'checkbox':
                return $attribute->getValue() !== null ? (bool) $attribute->getValue() : null;
                break;
            case 'image':
                return $attribute->getValue() ? base64_encode($attribute->getValue()['content']) : '';
                break;
            default:
                // Rest: text, textarea
                return ($attribute->getValue() !== null) && (trim($attribute->getValue()) !== '') ? strval($attribute->getValue()) : null;
                break;
        }
    }

    public function savesessionajax() {
        $params = Parameters::getInstance();
        if($params->getUrlParamValue('locked')){
            return false;
        }
        
        $session = Session::getInstance();
        $this->load();
        $attributes = $this->model->getAttributes();
        foreach ($attributes as $kAttr => $attr) {
            $name = $attr->getName();
            if(strpos($name, 'publication') !== false || strpos($name, 'readership') !== false){
                $session->setAttribute($name, $params->get($name));
                $params->set($name, $params->get($name), true);
//                $_POST[$name] = $params->get($name);
                if(!isset($_POST[$name])){
                    $_POST[$name] = "";
                    $session->setAttribute($name, "");
                    $params->set($name, "", true);
                }else{
                    $_POST[$name] = $params->get($name);
                }
            }else if($name == 'company_osh_osh_appform_osh_country' && !isset($_POST[$name])){
                $_POST[$name] = "";
            }
            $valueSession = $session->getAttribute($name);
            if (isset($_POST[$name])){
                $value = $_POST[$name];
            }
            if (isset($value)) {
                switch ($attr->getType()) {
                    case Attribute::TYPE_DROPDOWN:
                        $attr->setSelectedValues($value);
                        $session->setAttribute($attr->getName() . '_selected', $attr->getSelectedValues());
                        break;
                    case Attribute::TYPE_DROPDOWN_MULTIPLE:
                        $session->setAttribute($attr->getName() . '_selected', $value);
                        break;


                    case Attribute::TYPE_RADIO:
                        $attr->setValue($value);
                        $session->setAttribute($name, $value);
                        break;
                    case Attribute::TYPE_IMAGE:
//                        $value = str_replace(';ba e', ';base', $value);
                        $value = str_replace('data:image/png;ba e64,','',$value);
//                        $value = str_replace('data:image/jpg;ba e64,','',$value);
//                        $value = str_replace(' ', '+', $value);
                        $valueImage = array(
                            "mime" => "image/png",
                            "content" => $value
                        );
                        $attr->getValue($valueImage);
                        $session->setAttribute($name, $valueImage);
                        break;

                    default:
                        $session->setAttribute($name, $value);
                        break;
                }



                if ($attr->getType() == Attribute::TYPE_IMAGE) {
                    $value = str_replace(';ba e', ';base', $value);
                    $value = str_replace(' ', '+', $value);
                    $valueImage = array(
                        "mime" => "image/png",
                        "content" => $value
                    );

                    $attr->getValue($valueImage);
                    $session->setAttribute($name, $valueImage);
                } else {
                    $session->setAttribute($name, $value);
                }
            }
        }
        //Añadimos el eliminado de la variable returnCode de sesion para que al
        //navegar por las pestañas, si lo has eliminado no vuelva a aparecer
        if (isset($_SESSION['returnCode'])){
            $_SESSION['returnCode']="";
        }
    }
    public function isOtherUserField($name) {
        if((strpos($name, 'otheruser')) !== false){
            return true;
        }else{
            return false;
        }
    }

}
