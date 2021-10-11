define("discourse/plugins/discourse-solved/discourse/solved-route-map",["exports"],(function(e){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;e.default={resource:"user.userActivity",map:function(){this.route("solved")}}})),Ember.TEMPLATES["javascripts/discourse/connectors/user-activity-bottom/solved-list"]=Ember.HTMLBars.template({id:null,block:'{"symbols":[],"statements":[[4,"link-to",null,[["route"],["userActivity.solved"]],{"statements":[[0,"  "],[1,[28,"d-icon",["check-square"],null],false],[0," "],[1,[28,"i18n",["solved.title"],null],false],[0,"\\n"]],"parameters":[]},null]],"hasEval":false}',meta:{moduleName:"javascripts/discourse/connectors/user-activity-bottom/solved-list"}}),Ember.TEMPLATES["javascripts/discourse/connectors/user-summary-stat/solved-count"]=Ember.HTMLBars.template({id:null,block:'{"symbols":[],"statements":[[4,"link-to",null,[["route"],["userActivity.solved"]],{"statements":[[0,"  "],[1,[28,"user-stat",null,[["value","label","icon"],[[24,["model","solved_count"]],"solved.solution_summary","check-square"]]],false],[0,"\\n"]],"parameters":[]},null]],"hasEval":false}',meta:{moduleName:"javascripts/discourse/connectors/user-summary-stat/solved-count"}}),Ember.TEMPLATES["javascripts/discourse/connectors/bread-crumbs-right/solved-status-filter"]=Ember.HTMLBars.template({id:null,block:'{"symbols":[],"statements":[[4,"if",[[24,["siteSettings","solved_enabled"]]],null,{"statements":[[0,"  "],[1,[28,"combo-box",null,[["class","content","value","valueProperty","onChange"],["solved-status-filter",[24,["statuses"]],[24,["status"]],"value",[28,"action",[[23,0,[]],"changeStatus"],null]]]],false],[0,"\\n"]],"parameters":[]},null]],"hasEval":false}',meta:{moduleName:"javascripts/discourse/connectors/bread-crumbs-right/solved-status-filter"}}),define("discourse/plugins/discourse-solved/discourse/connectors/bread-crumbs-right/solved-status-filter",["exports","I18n","discourse/lib/url","discourse-common/lib/get-owner"],(function(e,t,s,a){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o={shouldRender:function(e,t){var s=(0,a.getOwner)(this).lookup("router:main");if(t.siteSettings.show_filter_by_solved_status&&"discovery.categories"!==s.currentPath){if(t.siteSettings.allow_solved_on_all_topics)return!0;var o=(0,a.getOwner)(this).lookup("controller:navigation/category");return o&&o.get("category.enable_accepted_answers")}return!1},setupComponent:function(e,s){var a=["all","solved","unsolved"].map((function(e){return{name:t.default.t("solved.topic_status_filter.".concat(e)),value:e}}));s.set("statuses",a);var o=window.location.search;o.match(/solved=yes/)?s.set("status","solved"):o.match(/solved=no/)?s.set("status","unsolved"):s.set("status","all")},actions:{changeStatus:function(e){var t=window.location,a=t.search,o=a.startsWith("?")?a.substr(1).split("&"):[];o=o.filter((function(e){return!e.startsWith("solved=")})),e&&"all"!==e&&(e="solved"===e?"yes":"no",o.push("solved=".concat(e))),a=o.length>0?"?".concat(o.join("&")):"",s.default.routeTo("".concat(t.pathname).concat(a).concat(t.hash))}}};e.default=o})),Ember.TEMPLATES["javascripts/discourse/connectors/topic-after-cooked/solved-panel"]=Ember.HTMLBars.template({id:null,block:'{"symbols":[],"statements":[[4,"if",[[24,["topic","accepted_answer"]]],null,{"statements":[[0,"  "],[7,"p",true],[10,"class","solved"],[8],[0,"\\n    "],[1,[28,"html-safe",[[24,["topic","acceptedAnswerHtml"]]],null],false],[0,"\\n  "],[9],[0,"\\n"]],"parameters":[]},null]],"hasEval":false}',meta:{moduleName:"javascripts/discourse/connectors/topic-after-cooked/solved-panel"}}),define("discourse/plugins/discourse-solved/discourse/connectors/category-custom-settings/solved-settings",["exports"],(function(e){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;e.default={actions:{onChangeSetting:function(e){this.set("category.custom_fields.enable_accepted_answers",e?"true":"false")}}}})),Ember.TEMPLATES["javascripts/discourse/connectors/category-custom-settings/solved-settings"]=Ember.HTMLBars.template({id:null,block:'{"symbols":[],"statements":[[4,"unless",[[24,["siteSettings","allow_solved_on_all_topics"]]],null,{"statements":[[0,"  "],[7,"h3",true],[8],[1,[28,"i18n",["solved.title"],null],false],[9],[0,"\\n  "],[7,"section",true],[10,"class","field"],[8],[0,"\\n    "],[7,"div",true],[10,"class","enable-accepted-answer"],[8],[0,"\\n      "],[7,"label",true],[10,"class","checkbox-label"],[8],[0,"\\n        "],[1,[28,"input",null,[["type","checked","change"],["checkbox",[28,"readonly",[[24,["category","enable_accepted_answers"]]],null],[28,"action",[[23,0,[]],"onChangeSetting"],[["value"],["target.checked"]]]]]],false],[0,"\\n        "],[1,[28,"i18n",["solved.allow_accepted_answers"],null],false],[0,"\\n      "],[9],[0,"\\n    "],[9],[0,"\\n  "],[9],[0,"\\n"]],"parameters":[]},null]],"hasEval":false}',meta:{moduleName:"javascripts/discourse/connectors/category-custom-settings/solved-settings"}}),define("discourse/plugins/discourse-solved/discourse/initializers/extend-for-solved-button",["exports","I18n","discourse/models/topic","discourse/models/user","discourse/raw-views/topic-status","discourse/helpers/topic-status-icons","discourse/lib/ajax-error","discourse/lib/plugin-api","discourse/lib/ajax","discourse/widgets/post-cooked","discourse/lib/utilities","discourse-common/lib/icon-library"],(function(e,t,s,a,o,n,c,r,i,l,u,d){"use strict";function p(e){var s=e.getCurrentUser();n.default.addObject(["has_accepted_answer","far-check-square","solved"]),e.includePostAttributes("can_accept_answer","can_unaccept_answer","accepted_answer"),e.addDiscoveryQueryParam&&e.addDiscoveryQueryParam("solved",{replace:!0,refreshModel:!0}),e.addPostMenuButton("solved",(function(e){var a=e.can_accept_answer,o=e.can_unaccept_answer,n=e.accepted_answer,c=s&&s.id===e.topicCreatedById,r=n||!a||c?"first":"second-last-hidden";return a?{action:"acceptAnswer",icon:"far-check-square",className:"unaccepted",title:"solved.accept_answer",label:"solved.solution",position:r}:o&&n?{action:"unacceptAnswer",icon:"check-square",title:o?"solved.unaccept_answer":"solved.accepted_answer",className:"accepted fade-out",position:r,label:"solved.solution"}:!a&&n?{className:"hidden",disabled:"true",position:r,beforeButton:function(e){return e("span.accepted-text",{title:t.default.t("solved.accepted_description")},[e("span",(0,d.iconNode)("check")),e("span.accepted-label",t.default.t("solved.solution"))])}}:void 0})),e.decorateWidget("post-contents:after-cooked",(function(e){if(1===e.attrs.post_number){var t=e.getModel();if(t){var s=t.topic;if(s.accepted_answer){var a=!!s.accepted_answer.excerpt,o="\n            <aside class='quote accepted-answer' data-post=\"".concat(s.get("accepted_answer").post_number,'" data-topic="').concat(s.id,"\">\n              <div class='title'>\n                ").concat(s.acceptedAnswerHtml,' <div class="quote-controls"></div>\n              </div>\n              <blockquote>\n                ').concat(s.accepted_answer.excerpt,"\n              </blockquote>\n            </aside>"),n="\n            <aside class='quote accepted-answer'>\n              <div class='title title-only'>\n                ".concat(s.acceptedAnswerHtml,"\n              </div>\n            </aside>"),c=new l.default({cooked:a?o:n},e);return e.rawHtml(c.init())}}}})),e.attachWidgetAction("post","acceptAnswer",(function(){var e=this,t=this.model,s=t.get("topic.postStream.posts").filter((function(e){return 1===e.post_number||e.accepted_answer}));!function(e){var t=e.topic;!function(e){e.get("postStream.posts").forEach((function(e){e.get("post_number")>1&&e.setProperties({accepted_answer:!1,can_accept_answer:!0,can_unaccept_answer:!1})}))}(t),e.setProperties({can_unaccept_answer:!0,can_accept_answer:!1,accepted_answer:!0}),t.set("accepted_answer",{username:e.username,post_number:e.post_number,excerpt:e.cooked}),(0,i.ajax)("/solution/accept",{type:"POST",data:{id:e.id}}).catch(c.popupAjaxError)}(t),s.forEach((function(t){return e.appEvents.trigger("post-stream:refresh",{id:t.id})}))})),e.attachWidgetAction("post","unacceptAnswer",(function(){var e=this.model,t=e.get("topic.postStream.posts").find((function(e){return 1===e.post_number}));!function(e){if(e.can_unaccept_answer){var t=e.topic;e.setProperties({can_accept_answer:!0,can_unaccept_answer:!1,accepted_answer:!1}),t.set("accepted_answer",void 0),(0,i.ajax)("/solution/unaccept",{type:"POST",data:{id:e.id}}).catch(c.popupAjaxError)}}(e),this.appEvents.trigger("post-stream:refresh",{id:t.id})})),e.registerConnectorClass&&(e.registerConnectorClass("user-activity-bottom","solved-list",{shouldRender:function(e,t){return t.siteSettings.solved_enabled}}),e.registerConnectorClass("user-summary-stat","solved-count",{shouldRender:function(e,t){return t.siteSettings.solved_enabled&&e.model.solved_count>0},setupComponent:function(){this.set("classNames",["linked-stat"])}}))}Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var v={name:"extend-for-solved-button",initialize:function(){s.default.reopen({acceptedAnswerHtml:Ember.computed("accepted_answer","id",(function(){var e=this.get("accepted_answer.username"),s=this.get("accepted_answer.post_number");return e&&s?t.default.t("solved.accepted_html",{icon:(0,d.iconHTML)("check-square",{class:"accepted"}),username_lower:e.toLowerCase(),username:(0,u.formatUsername)(e),post_path:"".concat(this.url,"/").concat(s),post_number:s,user_path:a.default.create({username:e}).path}):""}))}),o.default.reopen({statuses:Ember.computed((function(){var e=this._super.apply(this,arguments);return this.topic.has_accepted_answer?e.push({openTag:"span",closeTag:"span",title:t.default.t("topic_statuses.solved.help"),icon:"far-check-square",key:"solved"}):this.topic.can_have_answer&&this.siteSettings.solved_enabled&&this.siteSettings.empty_box_on_unsolved&&e.push({openTag:"span",closeTag:"span",title:t.default.t("solved.has_no_accepted_answer"),icon:"far-square"}),e}))}),(0,r.withPluginApi)("0.1",p),(0,r.withPluginApi)("0.8.10",(function(e){e.replaceIcon("notification.solved.accepted_notification","check-square")})),(0,r.withPluginApi)("0.11.0",(function(e){e.addAdvancedSearchOptions({statusOptions:[{name:t.default.t("search.advanced.statuses.solved"),value:"solved"},{name:t.default.t("search.advanced.statuses.unsolved"),value:"unsolved"}]})}))}};e.default=v})),define("discourse/plugins/discourse-solved/discourse/routes/user-activity-solved",["exports","discourse/routes/user-activity-stream"],(function(e,t){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var s=t.default.extend({userActionType:15,noContentHelpKey:"solved.no_solutions"});e.default=s})),define("discourse/plugins/discourse-solved/discourse/pre-initializers/extend-category-for-solved",["exports","discourse/models/category"],(function(e,t){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var s={name:"extend-category-for-solved",before:"inject-discourse-objects",initialize:function(){t.default.reopen({enable_accepted_answers:Ember.computed("custom_fields.enable_accepted_answers",{get:function(e){return"true"===Ember.get(this.custom_fields,e)}})})}};e.default=s}));
//# sourceMappingURL=/assets/plugins/discourse-solved-993a8ca9eb8a377c38c380027f257c194e93f896f9733b7c10929d992af21903.js.map