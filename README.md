Token Block
=============

Provides a block to display token replacements for referenced entities. 

Use
---

- Edit any layout that has an entity as context (e.g. a layout with path `node/%`, or a layout that has specific contexts such as `node` or `user`, or relationships such as "Author of content")
- In the "Add block" dialog, you will see a list of Token blocks that reference the available entities, such as "Tokens for node entities" or "Tokens for user account entities." 
- Select the block you want to add to the layout
- In the "Block content" field, type any text and insert tokens in the usual format, for example, `[node:title]` or `[node:author:name]` 

Please notice that adding inexistent tokens will not create a replacement. For example, if you selected "Tokens for node entities" and then add `[user:mail]`, this token will not be replaced, as it refers to user entities, not the available node entity. 

You may use chained tokens such as `[node:author:mail]`. 

Related modules
----

A related module that provides similar (but somewhat less flexible) functionality is [Node Property Block](https://github.com/backdrop-contrib/node_property_block), which allows administrators to display node fields like title, author, creation date, etc.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Author and maintainer
------

- argiepiano (https://github.com/argiepiano)

