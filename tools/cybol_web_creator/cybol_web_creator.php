<?php

if(empty($_POST['fname']))
{
    echo "Empty Array! Please define some methods to create a CYBOL script.";
    exit(0);
}
else
{
    $methods = $_POST['fname'];
    $xmlString = "";
    $xmlRow = "";

    $isPartTag = false;
    $isPropertyTag = false;
    $methodCounter = count($methods);
    $run = 0;
    foreach($methods as $m)
    {    $run++;

         $format = (!empty($m[6]))? "format=\"$m[6]\"" : "";
         $abstraction = (!empty($m[7]))? "abstraction=\"$m[7]\"" : $abstraction="";
         $language = (!empty($m[5]))? "language=\"$m[5]\"" : $language="";
         $encoding = (!empty($m[4]))? "encoding=\"$m[4]\"" : $encoding = "";

         if(strcmp($m[0] ,"PART") == 0)
         {
                 $xmlRow = "&lt;part name=\"".$m[1]."\" model=\"".$m[2]."\" channel=\"".$m[3]."\" ".$encoding." ".$language." ".$format." ".$abstraction." /&gt;";
                 $isPartTag = true;
         }

         if(strcmp($m[0] ,"PROPERTY") == 0)
         {
                 $xmlRow = "&lt;property name=\"".$m[1]."\" model=\"".$m[2]."\" channel=\"".$m[3]."\" ".$encoding." ".$language." ".$format." ".$abstraction." /&gt;";
               //  $xmlRow = "&lt;property name=\"".$m[1]."\" model=\"".$m[2]."\" channel=\"".$m[3]."\" encoding=\"".$m[4]."\" language=\"".$m[5]."\" format=\"".$m[6]."\" /&gt;";
                 $xmlRow = "<span id=\"xmlproperty\">".$xmlRow."</span>";
                 $isPropertyTag = true;
                 $isPartTag = false;
         }

         if($isPartTag && $isPropertyTag)
         {
                $xmlRow = "&lt;/part/&gt;<br>".$xmlRow;
                $isPropertyTag = false;
         }
         if($run == $methodCounter && $isPropertyTag)
         {
                $xmlRow = $xmlRow."<br>&lt;/part/&gt;";
         }

         $xmlString = $xmlString." <br> ".$xmlRow;
    }


}
     echo "<code><br><model>".$xmlString."<br><model></code>";
?>
