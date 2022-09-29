<?php

class TokenBlock extends Block {

  /**
   * {@inheritdoc}
   */
  function __construct($plugin_name, array $data) {
    parent::__construct($plugin_name, $data);

    $this->settings += array(
      'content' => '',
      'format' => NULL,
    );
  }

  /**
   * {@inheritdoc}
   */
  function getTitle() {
    return !empty($this->settings['title']) ? check_plain($this->settings['title']) : t('Token block');
  }

  /**
   * {@inheritdoc}
   */
  function form(&$form, &$form_state) {
     parent::form($form, $form_state);
    $token_types = array_keys($this->settings['contexts']);
    $variables = array(
      'token_types' => $token_types,
    );

    $form['content'] = array(
      '#type' => 'text_format',
      '#title' => t('Block content'),
      '#default_value' => $this->settings['content'],
      '#format' => $this->settings['format'],
      '#editor_uploads' => TRUE,
      '#rows' => 5,
      '#description' => theme('token_tree_link', $variables),
    );
  }

  /**
   * {@inheritdoc}
   */
  function formSubmit($form, &$form_state) {
    parent::formSubmit($form, $form_state);
    $this->settings['content'] = $form_state['values']['content']['value'];
    $this->settings['format'] = $form_state['values']['content']['format'];
  }

  /**
   * Returns the rendered content of this block.
   */
  function getContent() {
    if (!empty($this->settings['content'])) {
      $entity_type = $this->childDelta;
      $entity = $this->contexts[$entity_type]->data;
      $data = array($entity_type => $entity);
      return check_markup(token_replace($this->settings['content'], $data), $this->settings['format'], '', TRUE);
    }
  }

  /**
   * Creates an array of "child blocks" for display in the "Add Block" dialog.
   *
   * This allows a single entry in hook_block_info() to provide multiple
   * block instances displaying different fields.
   *
   * @see token_block_get_block_list()
   */
  function getChildren() {
    return token_block_get_block_list();
  }
}