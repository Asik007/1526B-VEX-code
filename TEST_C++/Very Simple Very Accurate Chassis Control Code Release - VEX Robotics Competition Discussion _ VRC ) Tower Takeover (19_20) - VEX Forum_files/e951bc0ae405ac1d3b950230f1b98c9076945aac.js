if ('define' in window) {
define("discourse/theme-5/initializers/theme-field-7-common-html-script-1", ["exports", "discourse/lib/plugin-api"], function (_exports, _pluginApi) {
  "use strict";

  Object.defineProperty(_exports, "__esModule", {
    value: true
  });
  _exports.default = void 0;

  var settings = require("discourse/lib/theme-settings-store").getObjectForTheme(5);

  var themePrefix = function themePrefix(key) {
    return "theme_translations.5.".concat(key);
  };

  var _default = {
    name: "theme-field-7-common-html-script-1",
    after: "inject-objects",
    initialize: function initialize() {
      (0, _pluginApi.withPluginApi)("0.8.8", function (api) {
        window.vexheader_setup = false;

        var setScrolled = function setScrolled() {
          $('.d-header').addClass('scrolled');
          $('.product_line_wrapper').hide();
        };

        var removeScrolled = function removeScrolled() {
          $('.d-header').removeClass('scrolled');
          $('.product_line_wrapper').show();
        };

        var setVexHeaderScrollEvent = function setVexHeaderScrollEvent() {
          var title = $('#topic-title');

          if (title[0]) {
            if ($(window).scrollTop() + $('.d-header').height() >= title[0].offsetTop) {
              setScrolled();
            } else {
              removeScrolled();
            }
          } else if ($('.posts.container')[0]) {
            if ($(window).scrollTop() >= $('.posts')[0].offsetTop) {
              setScrolled();
            } else {
              removeScrolled();
            }
          } else {
            removeScrolled();
          }

          $(window).unbind('scroll.vexheader');
          $(window).on('scroll.vexheader', function () {
            var posts = $('.posts.container');
            var title = $('#topic-title');

            if (title[0]) {
              if ($(window).scrollTop() >= title[0].offsetTop) {
                setScrolled();
              } else {
                removeScrolled();
              }
            } else if (posts[0]) {
              if ($(window).scrollTop() >= posts[0].offsetTop) {
                setScrolled();
              } else {
                removeScrolled();
              }
            }
          });
        };

        var setVexIconHoverEvents = function setVexIconHoverEvents() {
          $('.line_item').unbind('mouseover.vexheader');
          $('.line_item').unbind('mouseleave.vexheader');
          $('.line_item').on('mouseover.vexheader', function () {
            var current_line_item = $(this)[0].id;
            $('.selected').removeClass('current');
            $('#' + current_line_item + '_item').addClass('current');
          });
          $('.line_item').on('mouseleave.vexheader', function () {
            $('.selected').removeClass('current');
            $('#vexedr_item').addClass('current');
          });
        };

        var setVexHeaderResizeEvent = function setVexHeaderResizeEvent() {
          $(window).unbind('resize.vexheader');
          $(window).on('resize.vexheader', function () {
            setVexHeaderScrollEvent();
          });
        };

        api.addPostTransformCallback(function (e) {
          if (!window.vexheader_setup) {
            setVexHeaderResizeEvent();
            setVexHeaderScrollEvent();
            setVexIconHoverEvents();
            window.vexheader_setup = true;
          }
        });
        api.onPageChange(function (url) {
          setVexHeaderResizeEvent();
          setVexHeaderScrollEvent();
          setVexIconHoverEvents();
        });
        api.decorateWidget("home-logo:after", function (helper) {
          setVexHeaderResizeEvent();
          setVexHeaderScrollEvent();
          return helper.h("div.product_line_wrapper", [helper.h('a#vexrobotics.line_item', {
            href: 'https://www.vex.com/'
          }, helper.h('div.vex.item.vexrobotics_line', [helper.h('img.selected.current#vexedr_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexRed.svg',
            alt: 'VEX V5 Icon'
          }), helper.h('img.selected.#vexexp_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexRed.svg',
            alt: 'VEX EXP Icon'
          }), helper.h('img.selected#vex123_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexPurple.svg',
            alt: 'VEX 123 Icon'
          }), helper.h('img.selected#vexgo_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexLimeGreen.svg',
            alt: 'VEX GO Icon'
          }), helper.h('img.selected#vexiq_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexBlue.svg',
            alt: 'VEX IQ Icon'
          }), helper.h('img.selected#vexpro_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexGreen.svg',
            alt: 'VEX Pro Icon'
          }), helper.h('img.selected#vextoy_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexOrange.svg',
            alt: 'VEX Toys Icon'
          }), helper.h('img.selected#vexrobotics_item', {
            src: 'https://content.vexrobotics.com/vexheader/vexWhite.svg',
            alt: 'VEX Selected Icon'
          })])), helper.h('a#vex123.line_item', {
            href: 'https://www.vexrobotics.com/123'
          }, helper.h('div.item.123_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/123purple.svg',
            alt: '123 Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/123white.svg',
            alt: '123 Selected'
          })])), helper.h('a#vexgo.line_item', {
            href: 'https://www.vexrobotics.com/go'
          }, helper.h('div.item.go_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/GOlime.svg',
            alt: 'GO Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/GOwhite.svg',
            alt: 'GO Selected'
          })])), helper.h('a#vexiq.line_item', {
            href: 'https://www.vexrobotics.com/iq'
          }, helper.h('div.item.iq_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/iqBlue2.svg',
            alt: 'IQ Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/iqWhite2.svg',
            alt: 'IQ Selected'
          })])), helper.h('a#vexexp.line_item', {
            href: 'https://www.vexrobotics.com/exp'
          }, helper.h('div.item.exp_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/expRed.svg',
            alt: 'EXP Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/expWhite.svg',
            alt: 'EXP Selected'
          })])), helper.h('a#vexedr.line_item', {
            href: 'https://www.vexrobotics.com/v5'
          }, helper.h('div.item.edr_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/v5Red.svg',
            alt: 'EDR Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/v5White.svg',
            alt: 'EDR Selected'
          })])), helper.h('a#vexpro.line_item', {
            href: 'https://www.vexrobotics.com/pro'
          }, helper.h('div.item.pro_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/proGreen2.svg',
            alt: 'PRO Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/proWhite2.svg',
            alt: 'PRO Selected'
          })])), helper.h('a#vextoy.line_item', {
            href: 'https://www.vexrobotics.com/toys'
          }, helper.h('div.item.toy_line', [helper.h('img.unselected', {
            src: 'https://content.vexrobotics.com/vexheader/toysOrange.svg',
            alt: 'Toys Unselected'
          }), helper.h('img.selected', {
            src: 'https://content.vexrobotics.com/vexheader/toysWhite.svg',
            alt: 'Toys Selected'
          })]))]);
        });
      });
    }
  };
  _exports.default = _default;
});
}
