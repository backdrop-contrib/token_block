<?php

class TokenBlock extends BlockText {
  /**
   * Returns the rendered content of this block.
   */
  function getContent() {
    if (!empty($this->settings['content'])) {
      return check_markup(token_replace($this->settings['content']), $this->settings['format'], '', TRUE);
    }
  }
}