<?php
/**
 * Class Congrats
 * @author Joaquin Rua <joaquin.rua.conde@everis.com>
 * @version 1.0
 */
class Congrats extends Controller implements IController, IForm {
    /**
     * Class constructor
     * @param bool $directOutput
     */
    public function __construct($directOutput = true) {
        $this->directOutput = $directOutput;
    }

    /**
     * Retrieve the class name
     * @return string
     */
    public static function getName() {
        return strtolower(__CLASS__);
    }

    /**
     * Execute the controller
     */
    public function execute() {
        $params = Parameters::getInstance();
        $renderer = new Renderer(__CLASS__);
        $renderer->setViewPath($params->get('viewEntitiesPath'));
        $contentArray = array(
            'appurl' => APP_URL . '?route=' . $params->get('route'),
            'homeurl' => APP_URL,
            'title' => $params->get('title'),
            'hideButtons' => true,
            'fullwidth' => true,
            'printable' => false,
            'category' => $params->getUrlParamValue('entity')
        );
        $content = $renderer->render($contentArray);
        if ($this->directOutput) {
            print $content;
        } else {
            return $content;
        }
    }

    /**
     * Load an entity
     */
    public function load() {}

    /**
     * Save action
     */
    public function save() {}

    /**
     * Send action
     * @param bool $save
     */
    public function send($save = false) {
        header('Location: ' . APP_URL);
        die;
    }
}