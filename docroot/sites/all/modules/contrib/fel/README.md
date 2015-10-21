
## Table of contents ##

* About
* API
* Supported field types
* How it works: Theme replacements
    - Core replacements
    - Contrib replacements
* Related projects and issues


## About ##

Form API and field setting for manipulating the layout of primitive form
elements. Main features:

* Form attribute for placing the form `#description` before the input element
  (`#description_display`).
* Field configuration for moving the help text before or after the input
  element. This is useful for multi value fields or fields with a large input
  space where the help text falls far away from the field title.
* Form attribute for adding additional classes to form `#title` and
  `#description`s (`#title_classes` and `#description_classes`).
* Field labels and help texts have their own CSS classes (`fel-field-label` and
  `fel-field-help-text`) to separate them from additional `#title`s and
  `#description`s added by some field types. This is handy for themers and other
  modules that need to separate the configured texts from the rest.

## API ##

The main module, *Form element layout* (`fel.module`) provides the primitive
rendering and behavior around the following form attributes:

* `#description_display`: Where the `#description` should be rendered relative
  to its `#children`. Can be *before* or *after*. Default is *before* for
  fieldsets and *after* for the rest.
* `#description_classes`: Array of additional classes to add to the
  `#description` when rendered. The default '*description*' class is always
  added. It can be further customized by overriding the theme
  `fel_form_element_description`.
* `#title_classes`: Array of additional classes to add to the `#title` when
  rendered.

Example usage for developers/themers:

    $form['example'] = array(
      '#type' => 'textfield',
      '#title' => t("Example input"),
      '#description' => t("Example description of what this element does."),

      // Attributes honored by fel.module
      '#title_classes' => array('example'),
      '#description_classes' => array('important'),
      '#description_display' => 'before',
    );


## Supported field types ##

All element and field types core provide is supported by *Form element layout
fields* (`fel_fields.module`). In addition some popular contrib field modules
are supported:

* [Address Field                ](https://www.drupal.org/project/addressfield)
* [Date                         ](https://www.drupal.org/project/date)
* [Email field                  ](https://www.drupal.org/project/email)
* [Entity reference             ](https://www.drupal.org/project/entityreference)
* [Field Collection Table       ](https://www.drupal.org/project/field_collection_table)
* [Geofield                     ](https://www.drupal.org/project/geofield)
* [Link                         ](https://www.drupal.org/project/link)
* [Matrix                       ](https://www.drupal.org/project/matrix)
* [Media                        ](https://www.drupal.org/project/media)
* [Meta tags quick              ](https://www.drupal.org/project/metatags_quick)
* [Multiupload filefield widget ](https://www.drupal.org/project/multiupload_filefield_widget)
* [Multiupload imagefield widget](https://www.drupal.org/project/multiupload_imagefield_widget)

Otherwise it has a fall-back mechanism that recursively will attach the
appropriate Form API attributes for elements likely to be rendered. If it
doesn't and your favorite module doesn't respond to the configuration, please
issue a feature request for it!

Field modules may also provide support for `fel_fields.module` by adding a
plugin for it. This is documented in the [Advanced help][] section of this
module.

[advanced help]: https://www.drupal.org/project/advanced_help

## How it works: theme replacements ##

In order to alter the order of field elements and inject classes a few themes
need to be altered. Instead of hijacking existing themes through
`hook_theme_registry_alter()`, this module will as far as possible use
replacement themes. That is, replace `$element['#theme']` or
`$element['#theme_wrapper'][]` with our own version.

This makes it still possible for themers to replace or further alter the themes
by overriding the themes while keeping the functionality provided by this
module. The replacement functions are:


### Core replacements ###

Original theme                | Replacement theme
------------------------------|--------------------------
[form_element][]              | fel_form_element
[form_element_label][]        | fel_form_element_label
[text_format_wrapper][]       | fel_text_format_wrapper
[fieldset][]                  | fel_fieldset
[field_multiple_value_form][] | fel_fields_multiple_form

[form_element]:              https://api.drupal.org/api/drupal/includes!form.inc/function/theme_form_element/7
[form_element_label]:        https://api.drupal.org/api/drupal/includes!form.inc/function/theme_form_element_label/7
[text_format_wrapper]:       https://api.drupal.org/api/drupal/modules!filter!filter.module/function/theme_text_format_wrapper/7
[fieldset]:                  https://api.drupal.org/api/drupal/includes!form.inc/function/theme_fieldset/7
[field_multiple_value_form]: https://api.drupal.org/api/drupal/modules!field!field.form.inc/function/theme_field_multiple_value_form/7


### Contrib replacements ###

Module                 | Original theme                               | Replacement theme
-----------------------|----------------------------------------------|-----------------------------
Date                   | date_combo                                   | fel_date_combo
Field collection table | field_collection_table_multiple_value_fields | fel_fields_collection_table
Matrix                 | matrix_table                                 | fel_fields_matrix_table


## Related projects and issues ##

* [D8 issue: #314385](https://www.drupal.org/node/314385)
* [D8 issue: #2318757](https://www.drupal.org/node/2318757)
* D7 sandbox module: [Top Description][]. This module moves all element
  descriptions above the input element. For all forms all over. No settings to
  modify its behavior. Minimally maintained. Maintenance fixes only.
* D7 module: [Label Help][]. This module adds an additional text element that
  are displayed before the input element. It doesn't touch or move the existing
  field $instance['description'].
* D7 module: [Extra Field Description][]. Behaves exactly like Label Help.
* D7 module: [Better field description][]. Like the two above it adds an
  additional text for fields, not touching the original help text
  (`$instance['description']`). The twist here is that it extracts the editing
  of the text to a different page with different permission, allowing non-admins
  (like, say, editors) to edit it without messing up other field settings.
* D6 sandbox module: [Element shuffle][]. This the first version of Form element
  layout. The concept is the same, but was not suitable for D7 port and had some
  real context leakage. FEL was therefore rewritten from scratch.

[top description]:          https://www.drupal.org/sandbox/jrb/top_description
[label help]:               https://www.drupal.org/project/label_help
[extra field description]:  https://www.drupal.org/project/extra_field_description
[better field description]: https://www.drupal.org/project/better_field_descriptions
[element shuffle]:          https://www.drupal.org/sandbox/kaare/1132056
