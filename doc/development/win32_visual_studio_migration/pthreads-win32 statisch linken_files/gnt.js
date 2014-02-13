var fkl={_base16:"0A12B34C56D78E9F",encode:function(e){var d="";for(var b=0;b<e.length;b++){var f=e.charCodeAt(b);var c=f>>4;var a=f-(c*16);d+=this._base16[c]+this._base16[a];}return"fkl"+d;},decode:function(e){var d="";for(var b=0;b<e.length;b+=2){var c=this._base16.indexOf(e.charAt(b));var a=this._base16.indexOf(e.charAt(b+1));d+=String.fromCharCode((c*16)+a);}return d;},init:function(){var b=document.getElementsByTagName("span");var h=b.length;for(var e=0;e<h;e++){var f=b[e];if(typeof f=="object"){if(f.className.substring(0,4)=="ggnt"){var g="";if(f.className.indexOf(" ",0)!=-1){g=f.className.substring(4,f.className.indexOf(" ",4));}else{g=f.className.substring(4);}var k=this.decode(g);var a=document.createElement("a");a.href=k;if(f.className.indexOf("targetblank",0)!=-1){a.target="_blank";}if(f.title!=""){a.title=f.title;}if(f.id!=""){a.id=f.id;}for(var d=0;d<f.childNodes.length;d++){a.appendChild(f.childNodes[d].cloneNode(true));}var c=f.className.split("fkl"+g).join("");if(c!=""){a.className=c.substr(1);}f.parentNode.insertBefore(a,f);f.parentNode.removeChild(f);h--;e--;}}}}};fkl.init();

/**************************************/

function MM_jumpMenu(targ,selObj,restore){ //v3.0
  eval(targ+".location='"+selObj.options[selObj.selectedIndex].value+"'");
  if (restore) selObj.selectedIndex=0;
}

function isIE()
{
	if ((navigator.appName == "Microsoft Internet Explorer") && (navigator.appVersion.substring(0,1)>=4)) return true;
}

function isNS()
{
	if ((navigator.appName == "Netscape") && (navigator.appVersion.substring(0,1)>=4)) return true;
}

/***************************************
* Smileys
***************************************/

function storeCaret (formname, fieldname)
{
	var msgform = document.forms['' + formname + ''].elements['' + fieldname + ''];
	if (msgform.createTextRange)
	msgform.caretPos = document.selection.createRange().duplicate();
}

function addSmiley(formname, fieldname, text)
{
	var msgform = document.forms['' + formname + ''].elements['' + fieldname + ''];
	if (isIE())
	{
		if (msgform.createTextRange && msgform.caretPos) {
			var caretPos = msgform.caretPos;
			caretPos.text =
			caretPos.text.charAt(caretPos.text.length - 1) == ' ' ?
			text + ' ' : text;
		}
		else
		{
			var temp = document.forms['' + formname + ''].elements['' + fieldname + ''].value;
			document.forms['' + formname + ''].elements['' + fieldname + ''].value=temp+text;
		}
	}
	else
	{
		var temp = document.forms['' + formname + ''].elements['' + fieldname + ''].value;
		document.forms['' + formname + ''].elements['' + fieldname + ''].value=temp+text;
	}
	document.forms['' + formname + ''].elements['' + fieldname + ''].focus();
	return true;
}

/***************************************
* Actions sur cellules
***************************************/

function cellOver(cell, classSup)
{
	cell.className = 'line-over ' + classSup;
	return true;
}

function cellOut(cell, css, classSup)
{
	cell.className = 'line-' + css + ' ' + classSup ;
	return true;
}

/* formulaire */
function DeSelectMulti(champ)
{
	document.getElementById(champ).options.selectedIndex=-1
}

/*************************
* PopUp                  *
*************************/
function PopUp(page, largeur, hauteur, scroll)
{
	open(page,'popup','toolbars=0,directories=0,status=0,resizable=1,scrollbars=' + scroll + ',width=' + largeur + ',height=' + hauteur + '');
}

function PrintPopup(page)
{
	open(page,'popup','toolbars=1,directories=0,status=0,resizable=1,scrollbars=1,width=1000,height=500');
}

function SendPopup(page)
{
	open(page,'popup','toolbars=1,directories=0,status=0,resizable=1,scrollbars=0,width=1000,height=800');
}

/*******************
* ZOOM             *
*******************/
function ZoomArticle(image)
{
	page = "/divers/zoom.php?img=" + image + "#0";
	window.location.href = page;
	//open(page,'photo','toolbars=0,directories=0,status=0,resizable=1,scrollbars=1,width=800,height=600,top=100,left=100');
}

function ZoomTelecharger(image)
{
	page = "/telecharger/zoom.php?img=" + image + "#0";
	window.location.href = page;
	//open(page,'photo','toolbars=0,directories=0,status=0,resizable=1,scrollbars=1,width=800,height=600,top=100,left=100');
}

/** PriceMinister **/
function link0() 
{
	var s = '';
	for (i = 0; i < arguments.length; i++) {
	s = s + arguments[i];
	}
	document.location=s;
}
function link1() 
{
	var l = '';
	for (i = 0; i < arguments.length; i++) {
  	l = l + arguments[i];
	}
	window.open(l);
}
/** Degroup test **/
function Verifier_Numero_Telephone(num_tel)
{
	// Definition du motif a matcher
	var regex = new RegExp(/^(01|02|03|04|05|06|08)[0-9]{8}/gi);
	
	// Test sur le motif
	if(regex.test(num_tel))
	{
		return true;
	}
	else
	{
		alert('Le numero de telephonne n\'est pas valide');
		return false;
	}
}

function divtoggle(id)
{
	obj = document.getElementById(id);
	if (obj.style.display == 'none') {
		obj.style.display = '';
	}
	else {
		obj.style.display = 'none';
	}
}