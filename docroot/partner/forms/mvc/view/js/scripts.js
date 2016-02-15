/*
 * (CRG - #48 - 13.10.2015)
 * */
var idElNum=0;
var sn = [];
sn["Facebook"]=0;
sn["Twitter"]=0;
sn["Youtube"]=0;
sn["Linkedin"]=0;
sn["SlideShare"]=0;
sn["Pinterest"]=0;
sn["Google+"]=0;
var maxEachSN = 1;
var rrss = [];
var helpMessage = true;
rrss[0] = "company_osh_facebookprofile";
rrss[1] = "company_osh_slideshareprofile";
rrss[2] = "company_osh_twitterprofile";
rrss[3] = "company_osh_youtubeprofile";
rrss[4] = "company_osh_linkedinprofile";
rrss[5] = "company_osh_pinterestprofile";
rrss[6] = "company_osh_googleplusprofile";
function fillSN(args)
{
	var target = args["target"];
	var containerTitle = args["containerTitle"];
	var idTitle = args["idTitle"];
	var url = args["url"];
	var nameHiddenToChange = args["nameHiddenToChange"];
	var containerTitle = args["containerTitle"];
	var idTitle = nameHiddenToChange + "_title";
	var containerTitle = "container_"+idTitle;
	var typeSN = args["typeSN"] ;
	var html ="" + 
	"<div id='"+containerTitle+"' >" +
	"<div class='typeSN'>"+typeSN+" Profile:</div>"+
	"	<button id='delSN' class='delSN' data-hidden='" + nameHiddenToChange + "' type='button' data-selector='company_osh_selectsocialnetworks' data-target='" + containerTitle + "' >" +
	"		<img src='mvc/view/img/paper-bin.png' />" +
	"	</button>" +
	"	<div class='titleSN' id='" + idTitle + "'>" + url + "</div>" +
//	"	<button id='delSN' class='delSN' data-hidden='" + nameHiddenToChange + "' type='button' data-selector='company_osh_selectsocialnetworks' data-target='" + containerTitle + "' >" +
//	"		<img src='/osha/mvc/view/img/minus-4-xxl.png' />" +
//	"	</button>" +
	"</div>";
	args["target"].append(html);
	return html;//if it is needed
}	
function addSN(args)
{
	var typeSN = args["selOption"].data("sn");
	var nameHiddenToChange = args["selOption"].val();
	var idTitle= nameHiddenToChange + "_title";
	var url = args["selOption"].data("url") + args["textBox"].val();
	
	var data = [];
	//prepare to fillSN
	data["url"] = url;
	data["nameHiddenToChange"] = nameHiddenToChange;
	data["target"] = args["target"];
	data["typeSN"] = typeSN;
	if(sn[typeSN] < maxEachSN)
	{
		$("#"+nameHiddenToChange).val(url)//Cambiamos el valor del Hidden
		args["textBox"].val("");
		try {
			fillSN(data);
			$("#" + nameHiddenToChange).val(url);
			sn[typeSN]++;
		} catch (ex) {
			console.log("ex: " + ex);
		}
	}else
	{
		
//		alert("You can not select more than  " + maxEachSN + " type of social network");
                $("#maxSocialNetDialog").removeClass('hidden');
                document.location.href = "#top";
	}
}
function delSN(args)
{
	try {
		//Eliminamos el contenedor de texto
		args["target"].slideUp();
		args["target"].remove();
		// Cambiamos el valor de ese elemento hidden
		 //var a =args["hiddenField"].val("");
                 args["hiddenField"].attr("value","");
	} catch (ex) {
		console.log("ex: " + ex);
	}

	
	
}
//document.onreadystatechange = function(e){
//    if (document.readyState === 'complete'){
//        var resetSession = false;
//        var urlSearch = window.location.search;
//        var sessionId = "";
//        var oldSessionId = '<%= Session["oldSessionId"] %>';
//        if(urlSearch.indexOf("session_id")){
//            sessionId = urlSearch.substr(urlSearch.indexOf("session_id")+11,36);
//            alert("oldSessionId: " +oldSessionId + " newSessionId: " +sessionId);
////            if(oldSessionId == "" && sessionId != ""){
////                resetSession = true;
////            } else 
//                if (oldSessionId != "" && oldSessionId != sessionId){
//                 resetSession = true;
//            }
//        }
//        if(resetSession){
//            var cookies = document.cookie.split(";");
//            for (var i = 0; i < cookies.length; i++){   
//                var spcook =  cookies[i].split("=");
//                deleteCookie(spcook[0]);
//            }
//            function deleteCookie(cookiename){
//                var d = new Date();
//                d.setDate(d.getDate() - 1);
//                var expires = ";expires="+d;
//                var name=cookiename;
//                var value="";
//                document.cookie = name + "=" + value + expires;                    
//            }
//            window.location = ""; // TO REFRESH THE PAGE
//        }
//    }
//};

/*Método para deshabilitar las redes sociales. Nos apoyamos en un 
 * campo similar, ya que los deshabilitados van por attributes de PHP y ente caso no es válido. */
window.onload = function () {
    if($("#company_osh_homepage").prop("disabled")){
         $("#company_osh_selectsocialnetworks").prop("disabled", "disabled");
         $("#socialNetworkTextBox").prop("disabled", "disabled");
         $(".delSN").prop("disabled", "disabled");
         $("#plusSN").prop("disabled", "disabled");
    }
    $("body").css("cursor", "default");
    if($('.validation:visible').length > 0){
        if($('#osh_aboutyourorgsection').val() == true || $('#osh_aboutyourorgsection').val() == "true"){
            checkSectionsByCDB("ORGANISATION");
        }
        if($('#osh_gencontactinfsection').val() == true || $('#osh_gencontactinfsection').val() == "true"){
            checkSectionsByCDB("GENERAL_INFORMATION");
        }
        if($('#osh_aboutyourceosection').val() == true || $('#osh_aboutyourceosection').val() == "true"){
            checkSectionsByCDB("CEO");
        }
        if($('#osh_aboutyourrepsection').val() == true || $('#osh_aboutyourrepsection').val() == "true"){
            checkSectionsByCDB("OSH");
        }
        if($('#osh_tobecomeapartnersection').val() == true || $('#osh_tobecomeapartnersection').val() == "true"){
            checkSectionsByCDB("BECOME");
        }
        if($('#osh_supportforcampaignsection').val() == true || $('#osh_supportforcampaignsection').val() == "true"){
            checkSectionsByCDB("INVOLVEMENT");
        }
        if($('#osh_yourcampaignpledgesection').val() == true || $('#osh_yourcampaignpledgesection').val() == "true"){
            checkSectionsByCDB("PLEDGE");
        }
        if($('#osh_primarycontactsection').val() == true || $('#osh_primarycontactsection').val() == "true"){
            checkSectionsByCDB("PRIMARY_CONTACT");
        }
    }
}
function checkSectionsByCDB(dataSection){
//    setCheckSectionAttributte(dataSection,true);
     $('#form form :input[data-section="' + dataSection + '"]').prop("onlyread", "onlyread");
                $('#form form :input[data-section="' + dataSection + '"]').css({
                    'pointer-events': 'none',
                    'background-color': '#E3E3E4'
                });
                //Disabled the imageButtons
                $('.company_osh_logoimage_popup-modal').css({
                    'pointer-events': 'none'
                });
                //Disabled countries of activity
                $('.select2').css({
                    'pointer-events': 'none'
                });
    $('[data-section="' + dataSection + '"]*.validation').addClass("validation-pressed");
//    $(this).addClass("validation-pressed");

    if(dataSection=="GENERAL_INFORMATION"){
        $("#company_osh_selectsocialnetworks").prop("disabled", "disabled");
        $("#socialNetworkTextBox").prop("disabled", "disabled");
        $(".delSN").prop("disabled", "disabled");
        $("#plusSN").prop("disabled", "disabled");
    }
    if(dataSection=="PRIMARY_CONTACT"){
        $("#contact_osh_maincontactchange").css({
                            'pointer-events': 'none',
                            'background-color': '#E3E3E4'
        });
        $("#company_osh_orgname").prop("disabled", "disabled");
    }
     if(dataSection=="ORGANISATION"){
        $("#contact_osh_mainemail").prop("disabled", "disabled");
     }
}
function stopRKey(evt) { 
  var evt = (evt) ? evt : ((event) ? event : null); 
  var node = (evt.target) ? evt.target : ((evt.srcElement) ? evt.srcElement : null); 
  if ((evt.keyCode == 13) && (node.type=="text"))  {return false;} 
} 

document.onkeypress = stopRKey; 




/*
 * (/CRG - #48 - 13.10.2015)
 * 
 * */
/**
 * Check a single section to find validation errors
 * @param section
 */
function checkSingleSection(section) {
    return !($(".main-form *[data-error='true'][data-section='" + section + "']").length);
}

function validaImagenes(section) {
    
     if(section == "ORGANISATION"){
        var logoImage =$(".company_osh_logoimage_image_container img");
        //Los FOP no tienen logo
        if($(".company_osh_logoimage_image_container").length == 0){
            return true;
        }
        if(logoImage.attr("src") && (logoImage.attr("src") != null ||logoImage.attr("src") != "")){
            setErrorImagesRequired('company_osh_logoimage',false);
            return true;
        }else{
            setErrorImagesRequired('company_osh_logoimage',true);
            return false;
        }
     }else if(section == "CEO"){
        var ceoImage = $(".company_osh_ceoimage_image_container img");
        if( ceoImage.attr("src") && (ceoImage.attr("src") != null ||ceoImage.attr("src") != "")){
            setErrorImagesRequired('company_osh_ceoimage',false);
            return true;
        }else{
            setErrorImagesRequired('company_osh_ceoimage',true);
            return false;
        }
     }else{
         return true;
     }
    
}

    
    function setErrorImagesRequired(id,error) {
        $("#"+id + "_errormsg").remove();
        if(error){
            $("#"+id).addClass("error");
            $("#"+id).attr("data-error", "true");
//            $("#"+id).parent().parent().parent().append('<div id=' +id+"_errormsg" +' class="error-msg">The field is required</div>');
        }else{
            $("#"+id).removeClass("error");
            $("#"+id).attr("data-error", "");
//            $("#"+id + "_errormsg").remove();
        }
    
    }

    function checkSections() {
        var ret = false;
        $("#sidebar-top .section").each(function (id, item) {
            var elemId = $(item).attr("data-section");
            var validateElement ="#" + elemId + " >div.validation";
            if ($("#" + elemId).length) {
               // console.log(elemId + ".length: " +$("#" + elemId).length);
                $("." + elemId).addClass("sidebar-error");
                //hace validaciones
                
                //Workaround MainContactChange
//                if(elemId == "PRIMARY_CONTACT" && $('#contact_osh_maincontactchange').prop('checked')){
//                    $(".main-contact-change input").each(function (id, item) {
//                        $(item).removeClass("error");
//                        $(item).attr("data-error", "");
//                        $("#" + $(item).attr("id") + "_errormsg").remove();
//                        $("#confirmemail_errormsg").remove();
//                    });
//                }
                if(validaImagenes(elemId) && checkSingleSection(elemId))
                {
                 ////Va bien
                    if($(validateElement).is(":visible"))
                    {
                        //Si tiene el check verde visible
                        //Comprobamos que esté presionado
                        if($(validateElement).hasClass("validation-pressed"))
                        {
                            $("." + elemId).removeClass("sidebar-error");//Se pone en verde
                        }
                    }else
                    {//Si no está visible el check verde
                         $("." + elemId).removeClass("sidebar-error");//Se pone en verde
                    }

                }else
                {
                     //Falla
                    
                    $("." + elemId).addClass("sidebar-error");//Si está mal se pone con el aspa

                }
            }
        });
    }

function checkSectionsforValidation(elemId) {
        var ret = true;
            var validateElement ="#" + elemId + " >div.validation";
            if ($("#" + elemId).length) {
                if(validaImagenes(elemId) && checkSingleSection(elemId)){
                    ret = true;
                }else{
                    ret = false;
                }
            }
            return ret;
    }

checkSections();
$(document).ready(function () {
    var buttonPressed;
    $('#form form .required :input').each(function (id, item) {
        validateField(item);
    });

    //checkSections();
    /**
     * Retrieve an URL parameter
     * @param key
     * @returns {Array|{index: number, input: string}|string|string}
     */
    function getUrlVar(key) {
        var result = new RegExp(key + "=([^&]*)", "i").exec(window.location.search);
        return result && decodeURI(result[1]) || "";
    }

    /**
     * Validate a field via AJAX
     * @param field
     */
    function validateField(field) {
        //Workaround not validate pledge section
//        if($(field).attr("id") == 'involvement_osh_campaignpledge'){
//           if($(field).val()){
//               $(field).removeClass("error");
//               $(field).attr("data-error", "");
//           }else{
//               $(field).addClass("error");
//               $(field).attr("data-error", "true");
//           }
//        }else if($(field).attr("id") == 'involvement_osh_promoteandsupportcampaign'){
//           if($(field).val()){
//               $(field).removeClass("error");
//               $(field).attr("data-error", "");
//           }else{
//               $(field).addClass("error");
//               $(field).attr("data-error", "true");
//           }
//        }else 
            if($(field).attr("id") == 'company_osh_zipcode'){
             if($(field).val()){
               if($(field).val().length > 10){
                    $(field).addClass("error");
                    $(field).attr("data-error", "true");
                    $("#company_osh_zipcode_errormsg").remove();
                    $(field).parent().append('<div id="company_osh_zipcode_errormsg" class="error-msg">The maximum size of this field is 10</div>');
               }else{
                    $(field).removeClass("error");
                    $(field).attr("data-error", "");
                    $("#company_osh_zipcode_errormsg").remove();
                }
           }else{
               $(field).addClass("error");
               $(field).attr("data-error", "true");
               $("#company_osh_zipcode_errormsg").remove();
           }
           
        }else if($(field).attr("id") == 'helpMessage'){
        }else if($(field).attr("id") == 'contact_osh_confirm_mainemail'){
        }else if($(field).attr("id") == 'company_osh_logoimage_file' || $(field).attr("id") == 'company_osh_ceoimage_file'){
            $(field).removeClass("error");
            $(field).attr("data-error", "");
        }else{
        
//            var urlParamsArray = {
//                route: getUrlVar("route"),
//                ajax: true,
//                async: false,
//                action: "validateAttribute",
//                attribute: $(field).attr("id"),
//                contentType:"application/json; charset=utf-8",
//                dataType:"json",
//                value: $(field).val()
//            };
//            var urlParams = $.param(urlParamsArray);
//            var url = window.location.href;
//            if (url.indexOf("?") != -1) {
//                var pos = url.indexOf("?");
//                url = url.substr(0, pos);
//            }
//            url += "?" + urlParams;

    //        Evitamos que valide los campos de contact si el check maincontactchange está pulsado.
//            if(!isMainContact($(field))){
//                $.get(url, function (data, status) {
//                    var response = jQuery.parseJSON(data);
                    var response = true;
                    if($(field).prop("type") != "button"){
                        response = validateRequiredField($(field));
                    }
                    if (response) {
                        $(field).removeClass("error");
                        $(field).attr("data-error", "");
                        if ($("#" + response.id + "_errormsg").length) {
                            $("#" + response.id + "_errormsg").remove();
                        }
                    } else{
                        //Elimino el mensaje anterior para que los mails puedan sacar el error de formato.
                        $("#"+response.id + "_errormsg").remove();
                        $(field).addClass("error");
                        $(field).attr("data-error", "true");
//                        if (!$("#" + response.id + "_errormsg").length) {
//                            $(field).parent().append('<div id="' + response.id + '_errormsg" class="error-msg">' + response.message + '</div>');
//                        }
                    }
//                });
//            }
        }
    }
    
//    function isMainContact(field){
//        if($("#contact_osh_maincontactchange").prop('checked')){
//            if(($(field).attr("id") == "contact_osh_maincontactpersonfirstname") ||
//                  ($(field).attr("id") == "contact_osh_maincontactpersonlastname") ||
//                  ($(field).attr("id") == "contact_osh_positionmaincontactperson") ||
//                  ($(field).attr("id") == "contact_osh_mainemail") ||
//                  ($(field).attr("id") == "contact_osh_confirm_mainemail")){
//              
//              return true;
//            }else{
//                return false;
//            }
//        }else{
//            return false;
//        }
//    }
    function validateRequiredField(field){
        if($(field).val() == null || $(field).val() == ""){
            return false;
        }else
            return true;
    }
    
    function validateFieldSelected(field) {
        var urlParamsArray = {
            route: getUrlVar("route"),
            ajax: true,
            async: false,
            action: "validateAttribute",
            contentType:"application/json; charset=utf-8",
            dataType:"json",
            attribute: $(field).attr("id"),
            value: $(field).val()
        };
        var urlParams = $.param(urlParamsArray);
        var url = window.location.href;
        if (url.indexOf("?") != -1) {
            var pos = url.indexOf("?");
            url = url.substr(0, pos);
        }
        url += "?" + urlParams;
        $.get(url, function (data, status) {
            //var response = jQuery.parseJSON(data);
            var status = false;
            var response = jQuery.parseJSON(data);
            if($(field).val()!=null && $(field).val()!= ""){
                status = true;
            }
            if (status || response.status) {
                $(field).removeClass("error");
                $(field).attr("data-error", "");
                if ($("#" + response.id + "_errormsg").length) {
                    $("#" + response.id + "_errormsg").remove();
                }
            } else if(response.message != null) {
                $(field).addClass("error");
                $(field).attr("data-error", "true");
                if (!$("#" + response.id + "_errormsg").length) {
                    $(field).parent().append('<div id="' + response.id + '_errormsg" class="error-msg">' + response.message + '</div>');
                }
            }
        });
    }
    
//    (CRG - #133 - 26.10.2015)
    function validationAndPressed(eId){
        var validateElement ="#" + eId + " >div.validation";
        if(($(validateElement).hasClass("validation-pressed")))
        {
            return true;
        }else
        {
            return false;
        }
    }
    function validateSingleSection(elemId){
        if (!checkSingleSection(elemId)){
            $("." + elemId).addClass("sidebar-error");
            ret = false;
        } else
        {
            
            $("." + elemId).removeClass("sidebar-error");
        }
    }
    /**
     * Check all sections to find validation errors
     */



    /**
     * Trigger the field validation
     */
    $(".main-form .required input").on({
        change: function () {
            validateField(this);
        }
//        , blur: function () {
//            validateField(this);
//        }
    });
     $(".main-form .required select").on({
        change: function () {
            validateField(this);
        }
//        , blur: function () {
//            validateField(this);
//        }
    });
    $(".main-form .required textarea").on({
        change: function () {
            validateField(this);
        }
//        , blur: function () {
//            validateField(this);
//        }
    });

    $("#contact_osh_mainemail").on({
        blur: function () {
            $("#contact_osh_mainemailAux").val($("#contact_osh_mainemail").val());
        }, change: function () {
            $("#contact_osh_mainemailAux").val($("#contact_osh_mainemail").val());
        }
    });

//    $("#contact_osh_confirm_mainemail").on({
//        change: function () {
//            validateConfirmEmail(this);
//        }
//    });
    
     $("#company_osh_generalemail").on({
        change: function () {
            validateEmail(this);
        }
    });
    $('#contact_osh_otherusermail1').on({
        change: function () {
            validateEmail(this);
            nameAndMailFilled1(this);
        }
    });
    $('#contact_osh_otherusermail2').on({
        change: function () {
            validateEmail(this);
            nameAndMailFilled2(this);
        }
    });
    $('#contact_osh_otherusermail3').on({
        change: function () {
            validateEmail(this);
            nameAndMailFilled3(this);
        }
    });
        $('#contact_osh_otherusername1').on({
        change: function () {
            nameAndMailFilled1();
        }
    });
    $('#contact_osh_otherusername2').on({
        change: function () {
            nameAndMailFilled2();
        }
    });
    $('#contact_osh_otherusername3').on({
        change: function () {
            nameAndMailFilled3();
        }
    });
    $("#company_osh_orgname").on({
        blur: function () {
            //Set the value to the Aux
            $("#company_osh_orgnameAux").val($("#company_osh_orgname").val());
        }, change: function () {
            $("#company_osh_orgnameAux").val($("#company_osh_orgname").val());
        }
    });
    $('#company_osh_homepage').on({
        change: function () {
            validateWebFormat(this);
        }
    });
    $('#company_osh_dedicatedsite').on({
        change: function () {
            validateWebFormat(this);
        }
    });

    /**
     * Validate confirmation email
     */
    function validateConfirmEmail() {
        //Set the value to the Aux
        $("#contact_osh_mainemailAux").val($("#contact_osh_mainemail").val());
        if ($("#contact_osh_mainemail").val() != $("#contact_osh_confirm_mainemail").val() &&
                (!$("#contact_osh_mainemail").val() == "" && $("#contact_osh_confirm_mainemail").val() != undefined)) {
            $("#contact_osh_mainemail").addClass("error");
            $("#contact_osh_mainemail").attr("data-error", "true");
            $("#contact_osh_confirm_mainemail").addClass("error");
            $("#contact_osh_confirm_mainemail").attr("data-error", "true");
            if (!$("#confirmemail_errormsg").length) {
                $("#contact_osh_confirm_mainemail").parent().append('<div id="confirmemail_errormsg" class="error-msg">The email addresses must match</div>');
            }
        } else {
            $("#contact_osh_mainemail").removeClass("error");
            $("#contact_osh_mainemail").attr("data-error", "");
            $("#contact_osh_confirm_mainemail").removeClass("error");
            $("#contact_osh_confirm_mainemail").attr("data-error", "");
            $("#confirmemail_errormsg").remove();
        }
    }


    /**
     * If there are errors, the form cannot be submitted
     */
    $(".main-form").on({
        submit: function (e) {
            if (buttonPressed == "next") {
//                var enableFields = true;
                validateConfirmEmail();
                if ($(".main-form input[data-error='true']").length ||
                    $(".main-form textarea[data-error='true']").length ||
                    $(".main-form select[data-error='true']").length) {
//                    alert("Error: Some fields contain errors");
                    $("#dataErrorDialog").removeClass('hidden');
                    document.location.href = "#top";
                    styleChange(true);
                    e.preventDefault();
                    return false;
                } else if (!checkRequiredFields()) {
//                    alert("Error: You must fill all the required fields");
                    $("#fillRequiredDialog").removeClass('hidden');
                    document.location.href = "#top";
                    styleChange(true);
                    e.preventDefault();
                    return false;
                } else if ($('#form form').hasClass("current")
                    && ($('.validation').length > $('.validation.validation-pressed').length))
                    {
                    if (!confirm("There are fields unconfirmed. Do you want to continue?")) {
                        e.preventDefault();
//                        $(".validation").removeClass("validation-pressed");
//                        enableFields = false;
                    } else {
//                        $("#form form :input").prop("disabled", false);
                         styleChange(false);
//                         $(".validation").removeClass("validation-pressed");
                    }
                }

                
            }
        }
    });

    /**
     * Check that all the required fields are filled
     * @returns {boolean}
     */
    function checkRequiredFields() {
        var ret = true;
        var field;
        $("#form form .required .controls").each(function (id, item) {
            //WorkAround main contact change
            if($(item).find("input[type=text]").attr("data-section") == "PRIMARY_CONTACT" && $('#contact_osh_maincontactchange').prop('checked')){
                return true;
            }
            if (field = $(item).find("input[type=text]")) {
                if ($(field).attr("data-section") && !$(field).val()) {
                    ret = false;
                    return false;
                }
            } else if (field = $(item).find("textarea")) {
                if ($(field).attr("data-section") && !$(field).val()) {
                    ret = false;
                    return false;
                }
            } else if (field = $(item).find("select")) {
                if ($(field).attr("data-section") && !$(field).val()) {
                    ret = false;
                    return false;
                }
            }
        });
        if($('#next').attr('value').indexOf('Submit') != -1){
            if($('.sidebar-error').length){
                ret = false;
                return false;
            }
        }
        return ret;
    }

    function styleChange(required){
        if(required){
           $("#form form .required .controls .error").parent().addClass("postRequired");
        }else{
           $("#form form .required .controls .error").parent().removeClass("postRequired");
        }
    }

    /**
     * Add repeated blocks of information
     */
    $("#form").on("click", ".addOtherUser", function (e) {
        if($('#otherUserField2').hasClass('disabled')){
            $('#otherUserField2').removeClass('disabled');
            $('#otherUserField2').css({
            'display': 'initial'
            });
        }else if($('#otherUserField3').hasClass('disabled')){
            $('#otherUserField3').removeClass('disabled');
            $('#otherUserField3').css({
            'display': 'initial'
            });
        }else if($('#otherUserField1').hasClass('disabled')){
            $('#otherUserField1').removeClass('disabled');
            $('#otherUserField1').css({
            'display': 'initial'
            });
        }
        e.preventDefault();
    });

    /**
     * Remove a repeated block of information
     */
    $("#form").on("click", "#removeOtherUser1", function (e) {
        
        $('#otherUserField1').addClass('disabled');
        $('#otherUserField1').css({
            'display': 'none'
        });
        $('#contact_osh_otherusername1').val("");
        $('#contact_osh_otherusermail1').val("");
        $('#contact_osh_otheruserphone1').val("");
        e.preventDefault();
    });
    $("#form").on("click", "#removeOtherUser2", function (e) {
        
        $('#otherUserField2').addClass('disabled');
        $('#otherUserField2').css({
            'display': 'none'
        });
        $('#contact_osh_otherusername2').val("");
        $('#contact_osh_otherusermail2').val("");
        $('#contact_osh_otheruserphone2').val("");
        e.preventDefault();
    });
    $("#form").on("click", "#removeOtherUser3", function (e) {
        
        $('#otherUserField3').addClass('disabled');
        $('#otherUserField3').css({
            'display': 'none'
        });
        $('#contact_osh_otherusername3').val("");
        $('#contact_osh_otherusermail3').val("");
        $('#contact_osh_otheruserphone3').val("");
        e.preventDefault();
    });

    /**
     * Validation widget
     */
    $(".validation").click(function (e) {
        checkSections();//Comprueba la validez de las secciones en el menu izquierdo
        //Recorre todos los elementos que contienen la validación de la seccion actual
        var dataSection = $(this).attr("data-section");
        if ($(this).hasClass("validation-pressed")) {
            setCheckSectionAttributte(dataSection,false);
//            $('#form form :input[data-section="' + dataSection + '"]').prop("disabled", false);
                $('#form form :input[data-section="' + dataSection + '"]').prop("onlyread", false);
                $('#form form :input[data-section="' + dataSection + '"]').css({
                    'pointer-events': 'inherit',
                    'background-color': 'white'
                });
                //Enabled the imageButtons
                $('.company_osh_logoimage_popup-modal').css({
                    'pointer-events': 'inherit'
                });
                //Enabled countries of activity
                $('.select2').css({
                    'pointer-events': 'inherit'
                });
            $(this).removeClass("validation-pressed");
             if(dataSection=="GENERAL_INFORMATION"){
                $("#company_osh_selectsocialnetworks").prop("disabled", false);
                $("#socialNetworkTextBox").prop("disabled", false);
                $(".delSN").prop("disabled", false);
                $("#plusSN").prop("disabled", false);
            }
            if(dataSection=="PRIMARY_CONTACT"){
             $("#contact_osh_maincontactchange").css({
                        'pointer-events': 'inherit'
                    });
             }
        } else {
            //Nueva Petición: Section check cannot be checked until the mandatory fields are filled
            var validateSection = true;
            if(dataSection=="PRIMARY_CONTACT"){
                validateConfirmEmail();
             }
//            if(dataSection== "PRIMARY_CONTACT" && $('#contact_osh_maincontactchange').prop('checked')){
//                validateSection = false;
//            }
            if(checkSectionsforValidation(dataSection) || !validateSection){
                setCheckSectionAttributte(dataSection,true);
//                $('#form form :input[data-section="' + dataSection + '"]').prop("disabled", "disabled");
                $('#form form :input[data-section="' + dataSection + '"]').prop("onlyread", "onlyread");
                $('#form form :input[data-section="' + dataSection + '"]').css({
                    'pointer-events': 'none',
                    'background-color': '#E3E3E4'
                });
                //Disabled the imageButtons
                $('.company_osh_logoimage_popup-modal').css({
                    'pointer-events': 'none'
                });
                //Disabled countries of activity
                $('.select2').css({
                    'pointer-events': 'none'
                });
                
                $(this).addClass("validation-pressed");

                if(dataSection=="GENERAL_INFORMATION"){
                    $("#company_osh_selectsocialnetworks").prop("disabled", "disabled");
                    $("#socialNetworkTextBox").prop("disabled", "disabled");
                    $(".delSN").prop("disabled", "disabled");
                    $("#plusSN").prop("disabled", "disabled");
                }
                if(dataSection=="PRIMARY_CONTACT"){
                    $("#contact_osh_maincontactchange").css({
                        'pointer-events': 'none'
                    });
                    $("#company_osh_orgname").prop("disabled", "disabled");
                 }
                 if(dataSection=="ORGANISATION"){
                     $("#contact_osh_mainemail").prop("disabled", "disabled");
                 }
             }else{
//                alert("Section check cannot be checked until the mandatory fields are filled");
                $("#checkFieldsDialog").removeClass('hidden');
                document.location.href = "#top";
                }
        }
        
    });

    function setCheckSectionAttributte(dataSection,check){
        if(check){
            if(dataSection == 'ORGANISATION'){
                $('#osh_aboutyourorgsection').val("true");
            }else if(dataSection == 'GENERAL_INFORMATION'){
                $('#osh_gencontactinfsection').val("true");
            }else if(dataSection == 'CEO' || dataSection == "CHIEF"){
                $('#osh_aboutyourceosection').val("true");
            }else if(dataSection == 'OSH'){
                $('#osh_aboutyourrepsection').val("true");
            }else if(dataSection == 'BECOME'){
                $('#osh_tobecomeapartnersection').val("true");
            }else if(dataSection == 'INVOLVEMENT'){
                $('#osh_supportforcampaignsection').val("true");
            }else if(dataSection == 'PLEDGE'){
                $('#osh_yourcampaignpledgesection').val("true");
            }else if(dataSection == 'PRIMARY_CONTACT'){
                $('#osh_primarycontactsection').val("true");
            }
        }else{
            if(dataSection == 'ORGANISATION'){
                $('#osh_aboutyourorgsection').val("");
            }else if(dataSection == 'GENERAL_INFORMATION'){
                $('#osh_gencontactinfsection').val("");
            }else if(dataSection == 'CEO' || dataSection == "CHIEF"){
                $('#osh_aboutyourceosection').val("");
            }else if(dataSection == 'OSH'){
                $('#osh_aboutyourrepsection').val("");
            }else if(dataSection == 'BECOME'){
                $('#osh_tobecomeapartnersection').val("");
            }else if(dataSection == 'INVOLVEMENT'){
                $('#osh_supportforcampaignsection').val("");
            }else if(dataSection == 'PLEDGE'){
                $('#osh_yourcampaignpledgesection').val("");
            }else if(dataSection == 'PRIMARY_CONTACT'){
                $('#osh_primarycontactsection').val("");
            }
        }
    }





    /**
     * Save action
     */
    $("#save").click(function (e) {
        checkSections();
        buttonPressed = "save";
        var url = $("#form form").attr("action");
        console.log = url;
        var tmpRegex = new RegExp("(action=)[a-z]+", 'ig');
        console.log = tmpRegex;
        var newVal = "save";
        var newAction = url.replace(tmpRegex, '$1' + newVal);
        console.log = newAction;
        //validamos que los campos orgname y mainemail estén relleno antes de hacer el save.
        if($("#company_osh_orgnameAux").val() == '' ||
                $("#contact_osh_mainemailAux").val() == ''){
//            alert("The fields Company/Organisation name and E-mail of the Primary Contact are required for save the information");
            $("#nameandemailrequiredDialog").removeClass('hidden');
            document.location.href = "#top";
        }else{   
        $("#form form").attr("action", newAction);
        $("#form form").submit();
    }
    });

    /**
     * Save action
     */
    $(".guardarImg").click(function (e) {
        var targetElement = "." + $(this).attr("data-target");
        var imageData = $(this).parent().find(".thumbBox").html();
        $(targetElement).html(imageData);
        e.preventDefault();
        $.magnificPopup.close();
        delete $.magnificPopup.instance.popupsCache[$(this).attr("data-cropperkey")];
        $.magnificPopup.instance.popupsCache = {};
    });

    /**
     * Next action
     */
    $("#next").click(function (e) {
        buttonPressed = "next";
        checkSections();
    });

    /**
     * Trigger the section validation
     */
    setInterval(checkSections, 300);

    /**
     * Dropdown multiple
     */
    $(".dropdown-multiple").select2();

    $("#refresh").click(function (e) {
        $("#captcha").attr("src", 'lib/securimage/securimage_show.php?' + Math.random());
        return false;
    });
    if (!$('#contact_osh_otherusername2').val() && !$('#contact_osh_otherusermail2').val()) {
        $('#otherUserField2').addClass('disabled');
        $('#otherUserField2').css({
            'display': 'none'
        });
    }
    if (!$('#contact_osh_otherusername3').val() && !$('#contact_osh_otherusermail3').val()) {
        $('#otherUserField3').addClass('disabled');
        $('#otherUserField3').css({
            'display': 'none'
        });
    }

    /**
     * Show / Hide Disclaimer
     */
    $('#a_disclaimer').click(function () {
        var div_class = $('#div_disclaimer_text');
        if (div_class.hasClass('hidden')) {
            div_class.removeClass('hidden');
        } else {
            div_class.addClass('hidden');
        }
    });

    /**
     * Save Data and Print
     */
    $('.action-print').click(function () {
        if ($(".main-form form").length) {
            var action = $(".main-form form").attr("action") + "&print=true";
            $(".main-form form").attr("action", action);
//            if ($("#save").length) {
//                $("#save").trigger("click");
//            } else {
            var dataAjax = $(this).data("ajax");
            saveSessionAjax(dataAjax);
                window.open($(this).attr("data-href"), 'popup');
//            }
        } else {
            var dataAjax = $(this).data("ajax");
            saveSessionAjax(dataAjax);
            window.open($(this).attr("data-href"), 'popup');
        }
    });
    $('.action-pdf').click(function () {
        if ($(".main-form form").length) {
            var action = $(".main-form form").attr("action") + "&pdf=true";
            $(".main-form form").attr("action", action);
//            if ($("#save").length) {
//                $("#save").trigger("click");
//            } else {
                window.open($(this).attr("data-href"), 'popup');
//            }
        } else {
            window.open($(this).attr("data-href"), 'popup');
        }
    });

    /**
     * Main contact change functionality
     */
    $(".main-contact-change-checkbox").click(function () {
        if ($(this).prop('checked')) {
//            var contactBackup = $(".main-contact-change").clone();
//            $(contactBackup).addClass("main-contact-change-backup");
            $(".main-contact-change input").each(function (id, item) {
//                $(contactBackup).find("#" + $(item).attr("id")).val($(item).val());
                
                $('#'+$(item).attr("id")+'_clone').val($(item).val());
                $('#'+$(item).attr("id")+'_clone').addClass("main-contact-change-backup");
                $(item).val("");
                $(item).removeClass("error");
                $(item).attr("data-error", "");
                $("#"+$(item).attr("id")+"_errormsg").remove();
                
            });
            $("#confirmemail_errormsg").remove();
//            $(contactBackup).appendTo(".main-contact-change");
        } else {
            $(".main-contact-change-backup").each(function (id, item) {
                $("#"+$(item).attr("id").substr(0,$(item).attr("id").indexOf("_clone"))).val($(item).val());
//                $(".main-contact-change").find("#" + $(item).attr("id")).val($(item).val());
            });
//            $(".main-contact-change").remove(".main-contact-change-backup");
        }
    });

    /**
     * Combined checkbox event
     */
    $(".combined-checkbox").click(function () {
        var target = "#" + $(this).attr("data-target");
        $(target).toggle();
        if ($(target).is(":hidden")) {
            $(target).val("");
        }else{
            if($(target).val() == ""){
                $(target).val("Yes.");
            }
            $(target).css({
            'margin-top': '1%'
            });
        }
    });
    
    
     $(".close").click(function (e) {
         $("#container-message").addClass('hidden');
         //Insert a class in a static object.
         
         $("#helpMessage").val("false");
     });
     if($("#helpMessage").val()== "false"){
         $("#container-message").addClass('hidden');
     }
     $(".closeDialog").click(function (e) {
         $(".dialog").addClass('hidden');
         $(".saveDialog").addClass('hidden');
     });
     
     if($('.disabledEmailForMF').length == 1){
         $("#contact_osh_mainemail").prop("disabled", "disabled");
     }

    /**
     * Triggers the validations
     */
    //    (CRG - #48 - 15.10.2015)
    /*
     * Comento los eventos
     */
            $(".main-form .field").each(function (id, item) {
                $(item).focus();
                $(item).blur();
            });
    //    (/CRG - #48 - 15.10.2015)

    $(".main-form .field").first().focus();
    /*
     * (CRG  - #48 - 13.10.2015)
     * 
     */
    $("#form").on("click",".delSN",function(e){
    	
    		var args = [];
    		var t = $(this).data("target");
    		var h = $(this).data("hidden");
    		args["sn"] = $(this).data("sn");
    		args["selectorName"] = $(this).data("selector");
    		args["target"] = $("#" + t);
    		var referencedOption = $("option[value='"+ h +"']");
    		var typeSN = referencedOption.data("sn");
    		args["h"] = h;
    		args["hiddenField"] = $("#" + h);
    		
    		try {
				delSN(args);
				sn[typeSN]--;
			} catch (ex) {
				console.log("ex: " + ex);
			}
    		
    	}
    )
    $("#plusSN").on({
    	//+
    	click: function (e){
    		
	    	
    		var args = [];
	    	args["selectorName"] = $(this).data("selector");
	    	args["selector"]  = $("#"+args["selectorName"]);//select
	    	args["textBox"] = args["selector"].data("tb");
	    	args["textBox"] = $("#" + args["textBox"]);
	    	args["plusSN"] = $(this);//propio boton
	    	args["target"] = $("#" + $(this).data("target"));//Donde se mostrarán las urls
	    	args["selOption"] = $("#" + args["selector"].attr("id") + " option:selected");
	    	if(args["textBox"].val() != "" &&  args["textBox"].val() != undefined)
	    	{
                    try{
			addSN(args);
                    } catch (ex){
			console.log("ex:" + ex);
                    }
    		}else{
    		}
    	}
    });
    /*
     * Loads all social networks data in divs for loading  as appears in image
     * 		needs data: 
     * var target = args["target"];
    	var containerTitle = args["containerTitle"];
    	var idTitle = args["idTitle"];
    	var url = args["url"];
     *	var nameHiddenToChange = args["nameHiddenToChange"];
     *	var containerTitle = args["containerTitle"];
     * 			- 
     * */
    for(rs in rrss)
    {
    	idElement = rrss[rs];
    	var e = $("#"+idElement);//hidden element
    	
    	var data = [];
    	referencedOption = $("option[value='"+idElement+"'");
    	var typeSN = referencedOption.data("sn");
    	if(e.val()!= "" && referencedOption)
    	{
    		sn[typeSN]++;
    	}
    	var t = referencedOption.data("target");
    	data["target"] = $("#" + t);
    	data["nameHiddenToChange"] = idElement;
    	data["option"] = $("#" + e.data("option"));
    	data["url"]  = e.val();
    	data["typeSN"] = typeSN;
    	if(e)
    	{
	    	if(e.val() != "" && e.val() != " " && e.val() != undefined)
	    	{
	    		try {
	    			
					fillSN(data);
				} catch (ex) {
					// TODO: handle exception
					console.log("ex: " + ex);
				}
	    		
	    	}
    	}
    }

    /*
     *(/CRG  - #48 - 13.10.2015)
     * 
     */
//    (CRG)29.10.2015

    $("li.section a").click(function(e){
        enableFields();
        e.preventDefault();
        var serializedForm = $("form").serialize();
        var dataAjax = $(this).data("ajax");
        var href =  $(this).attr("href");
        var logoImage =$(".company_osh_logoimage_image_container img");

        if( logoImage.attr("src") && (logoImage.attr("src") != null ||logoImage.attr("src") != "") )
        {
            var valueLogoImage = logoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_logoimage="+valueLogoImage;
            
        }
        var ceoImage = $(".company_osh_ceoimage_image_container img");
        if( ceoImage.attr("src") && (ceoImage.attr("src") != null ||ceoImage.attr("src") != "") )
        {
            var valueLogoImage = ceoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_ceoimage="+valueLogoImage;
        }
        $("body").css("cursor", "progress");
        $.ajax({
            url: dataAjax,
            data: serializedForm,
            type: "post",
            success: function( data, textStatus,jqXHR){
                document.location.href = href;//Lleva al enlace
            }
        });
//        $(this).trigger("click");
    });
    
    $("li.section-title a").click(function(e){
        enableFields();
        e.preventDefault();
        var serializedForm = $("form").serialize();
        var dataAjax = $(this).data("ajax");
        var href =  $(this).attr("href");
        var logoImage =$(".company_osh_logoimage_image_container img");

        if( logoImage.attr("src") && (logoImage.attr("src") != null ||logoImage.attr("src") != "") )
        {
            var valueLogoImage = logoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_logoimage="+valueLogoImage;

        }
        var ceoImage = $(".company_osh_ceoimage_image_container img");
        if( ceoImage.attr("src") && (ceoImage.attr("src") != null ||ceoImage.attr("src") != "") )
        {
            var valueLogoImage = ceoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_ceoimage="+valueLogoImage;
        }
        $("body").css("cursor", "progress");
        $.ajax({
            url: dataAjax,
            data: serializedForm,
            type: "post",
            success: function( data, textStatus,jqXHR){
                document.location.href = href;//Lleva al enlace
            }
        });
//        $(this).trigger("click");
    });

    $(".progressbar-text-a").click(function(e){
        enableFields();
        e.preventDefault();
        var serializedForm = $("form").serialize();
        var dataAjax = $(this).data("ajax");
        var href =  $(this).attr("href");
        var logoImage =$(".company_osh_logoimage_image_container img");

        if( logoImage.attr("src") && (logoImage.attr("src") != null ||logoImage.attr("src") != "") )
        {
            var valueLogoImage = logoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_logoimage="+valueLogoImage;

        }
        var ceoImage = $(".company_osh_ceoimage_image_container img");
        if( ceoImage.attr("src") && (ceoImage.attr("src") != null ||ceoImage.attr("src") != "") )
        {
            var valueLogoImage = ceoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_ceoimage="+valueLogoImage;
        }
        
        $("body").css("cursor", "progress");
        $.ajax({
            url: dataAjax,
            data: serializedForm,
            type: "post",
            success: function( data, textStatus,jqXHR){
                document.location.href = href;//Lleva al enlace
            }
        });
//        $(this).trigger("click");
    });
    
    function enableFields(){
        /*Habilitamos los campos para que sean mandados a CRM */
                $('#form form input:disabled,#form form select:disabled,#form form textarea:disabled').prop("disabled",false);
                $("#company_osh_selectsocialnetworks").prop("disabled", false);
                $("#socialNetworkTextBox").prop("disabled", false);
                $(".delSN").prop("disabled", false);
                $("#plusSN").prop("disabled", false);
    }
    
    function saveSessionAjax(dataAjax){
        var serializedForm = $("form").serialize();
//        var dataAjax = $(this).data("ajax");
        var href =  $(this).attr("href");
        var logoImage =$(".company_osh_logoimage_image_container img");

        if( logoImage.attr("src") && (logoImage.attr("src") != null ||logoImage.attr("src") != "") )
        {
            var valueLogoImage = logoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_logoimage="+valueLogoImage;

        }
        var ceoImage = $(".company_osh_ceoimage_image_container img");
        if( ceoImage.attr("src") && (ceoImage.attr("src") != null ||ceoImage.attr("src") != "") )
        {
            var valueLogoImage = ceoImage.attr("src");
            valueLogoImage = valueLogoImage.replace("\s", "+");
            serializedForm += "&company_osh_ceoimage="+valueLogoImage;
        }
        $.ajax({
            url: dataAjax,
            data: serializedForm,
            type: "post",
            success: function( data, textStatus,jqXHR){
                
            }
        });
    }
    $("#printpage").click(function (e) {
        window.print();
     });
    $(".company_osh_ceoimage_popup-modal").click(function (e) {
        document.location.href = "#top";
     });
     
     //Redirect to the private zone from congrats.
     $(".privateZoneredirect").click(function (e) {
        window.top.location.href = "https://www.healthy-workplaces.eu/all-ages-splash-page/"; 
     });
     $(".privateZoneredirectMF").click(function (e) {
        var partner_nid = $('#partner_nid').val();
        var language = $('#language').val();
        if(partner_nid != null && partner_nid != "" && language != null && language != ""){
            var homeurl = $('#appurl').val();
            var url = homeurl + language + "/node/" + partner_nid;
            window.top.location.href = url;
        }else{
            window.top.location.href = "https://www.healthy-workplaces.eu/all-ages-splash-page/"; 
        }
     });


//Center the progressbar in congrats view
     if($(".thank-you").length){
         $(".row").css("float","left");
         $(".row").css("margin-left","-30px");
         $(document).scrollTop(0);
     }
     
    function validateEmail(email) {
        var re = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
        if(!re.test(email.value) && email.value){        
            $('#'+email.id).addClass("error");
            $('#'+email.id).attr("data-error", "true");
            if (!$('#'+email.id+'_emailformat_errormsg').length) {
                $('#'+email.id).parent().append('<div id="'+email.id+'_emailformat_errormsg" class="error-msg">The field must be a valid email address</div>');
            }
        } else {
            $('#'+email.id).removeClass("error");
            $('#'+email.id).attr("data-error", "");
            $('#'+email.id+'_emailformat_errormsg').remove();
        }
    }
    if(($('#contact_osh_otherusername1').val() != "" && $('#contact_osh_otherusername1').val() != undefined) 
            || ($('#contact_osh_otherusermail1').val() != "" &&$('#contact_osh_otherusermail1').val() != undefined)){
        nameAndMailFilled1();
    }
    if(($('#contact_osh_otherusername2').val() != "" && $('#contact_osh_otherusername2').val() != undefined) 
            || ($('#contact_osh_otherusermail2').val() != "" &&$('#contact_osh_otherusermail2').val() != undefined)){
        nameAndMailFilled1();
    }
    if(($('#contact_osh_otherusername3').val() != "" && $('#contact_osh_otherusername3').val() != undefined) 
            || ($('#contact_osh_otherusermail3').val() != "" &&$('#contact_osh_otherusermail3').val() != undefined)){
        nameAndMailFilled1();
    }
    
    function nameAndMailFilled1(){
       if($('#contact_osh_otherusername1').val() != "" && $('#contact_osh_otherusermail1').val() == ""){
            $("#contact_osh_otherusermail1").addClass("error");
            $("#contact_osh_otherusermail1").attr("data-error", "true");
            if (!$("#contact_osh_otherusermail1_required_errormsg").length) {
                $("#contact_osh_otherusermail1").parent().append('<div id="contact_osh_otherusermail1_required_errormsg" class="error-msg">The field is required</div>');
            }
       }else if($('#contact_osh_otherusername1').val() == "" && $('#contact_osh_otherusermail1').val() != ""){
            $("#contact_osh_otherusername1").addClass("error");
            $("#contact_osh_otherusername1").attr("data-error", "true");
            if (!$("#contact_osh_otherusername1_required_errormsg").length) {
                $("#contact_osh_otherusername1").parent().append('<div id="contact_osh_otherusername1_required_errormsg" class="error-msg">The field is required</div>');
            }
       }else{
           $("#contact_osh_otherusername1").removeClass("error");
           $("#contact_osh_otherusername1").attr("data-error", "");
           $("#contact_osh_otherusername1_required_errormsg").remove();
           $("#contact_osh_otherusermail1").removeClass("error");
           $("#contact_osh_otherusermail1").attr("data-error", "");
           $("#contact_osh_otherusermail1_required_errormsg").remove();
       }
    }
    function nameAndMailFilled2(){
       if($('#contact_osh_otherusername2').val() != "" && $('#contact_osh_otherusermail2').val() == ""){
            $("#contact_osh_otherusermail2").addClass("error");
            $("#contact_osh_otherusermail2").attr("data-error", "true");
            if (!$("#contact_osh_otherusermail2_required_errormsg").length) {
                $("#contact_osh_otherusermail2").parent().append('<div id="contact_osh_otherusermail2_required_errormsg" class="error-msg">The field is required</div>');
            }
       }else if($('#contact_osh_otherusername2').val() == "" && $('#contact_osh_otherusermail2').val() != ""){
            $("#contact_osh_otherusername2").addClass("error");
            $("#contact_osh_otherusername2").attr("data-error", "true");
            if (!$("#contact_osh_otherusername2_required_errormsg").length) {
                $("#contact_osh_otherusername2").parent().append('<div id="contact_osh_otherusername2_required_errormsg" class="error-msg">The field is required</div>');
            }
       }else{
           $("#contact_osh_otherusername2").removeClass("error");
           $("#contact_osh_otherusername2").attr("data-error", "");
           $("#contact_osh_otherusername2_required_errormsg").remove();
           $("#contact_osh_otherusermail2").removeClass("error");
           $("#contact_osh_otherusermail2").attr("data-error", "");
           $("#contact_osh_otherusermail2_required_errormsg").remove();
       }
    }
    function nameAndMailFilled3(){
       if($('#contact_osh_otherusername3').val() != "" && $('#contact_osh_otherusermail3').val() == ""){
            $("#contact_osh_otherusermail3").addClass("error");
            $("#contact_osh_otherusermail3").attr("data-error", "true");
            if (!$("#contact_osh_otherusermail3_required_errormsg").length) {
                $("#contact_osh_otherusermail3").parent().append('<div id="contact_osh_otherusermail3_required_errormsg" class="error-msg">The field is required</div>');
            }
       }else if($('#contact_osh_otherusername3').val() == "" && $('#contact_osh_otherusermail3').val() != ""){
            $("#contact_osh_otherusername3").addClass("error");
            $("#contact_osh_otherusername3").attr("data-error", "true");
            if (!$("#contact_osh_otherusername3_required_errormsg").length) {
                $("#contact_osh_otherusername3").parent().append('<div id="contact_osh_otherusername3_required_errormsg" class="error-msg">The field is required</div>');
            }
       }else{
           $("#contact_osh_otherusername3").removeClass("error");
           $("#contact_osh_otherusername3").attr("data-error", "");
           $("#contact_osh_otherusername3_required_errormsg").remove();
           $("#contact_osh_otherusermail3").removeClass("error");
           $("#contact_osh_otherusermail3").attr("data-error", "");
           $("#contact_osh_otherusermail3_required_errormsg").remove();
       }
    }
    function validateWebFormat(web){
//        var re = /((http|ftp|https):\/\/+)?(www.+)?[0-9A-Za-z]+\.+[0-9A-Za-z]/;
        if(web.value){
            var re = /[0-9A-Za-z]+\.+[0-9A-Za-z]/;
            var aux = web.value.toLowerCase();
            var http = aux.indexOf("http://");
            var https = aux.indexOf("https://");
            var httpIncluded = false;
            if(http != -1 || https!= -1){
                aux = web.value.substr(web.value.indexOf("//")+2);
                httpIncluded = true;
            }
            var www = aux.indexOf("www.");
             if(www!= -1){
                aux = web.value.substr(web.value.indexOf("www.")+4);
            }
            if(!re.test(aux) || web.value.indexOf(" ")!= -1 || !httpIncluded){        
                $('#'+web.id).addClass("error");
                $('#'+web.id).attr("data-error", "true");
                if (!$('#'+web.id+'_webformat_errormsg').length) {
                    $('#'+web.id).parent().append('<div id="'+web.id+'_webformat_errormsg" class="error-msg">The field must be a valid web url</div>');
                }
            } else {
                $('#'+web.id).removeClass("error");
                $('#'+web.id).attr("data-error", "");
                $('#'+web.id+'_webformat_errormsg').remove();
            }
        }else{
                $('#'+web.id).removeClass("error");
                $('#'+web.id).attr("data-error", "");
                $('#'+web.id+'_webformat_errormsg').remove();
        }
    }
    $("#nextInLocked").click(function (e) {
        if($("#nextInLocked").val().indexOf("involvement") != -1){
//            $("#progressbar-2").click();
            document.location.href = "?route=involvement";
        }else if($("#nextInLocked").val().indexOf("primary") != -1){
//            $("#progressbar-3").click();
            document.location.href = "?route=contact";
        }
    });
//     $(".upArrow").click(function (e) {
//        window.top.location.href = "#top";
//    });
if($("#contact_osh_mainemail").prop("disabled")){
    $('#contact_osh_mainemail').parent().append('<p class="help-block">This field cannot be directly changed in the form. If you want to modify it, please, contact EU-OSHA in partners@healthy-workplaces.eu</p>');
}
});
