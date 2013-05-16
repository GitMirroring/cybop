package cybol_eclipse_plugin.editor;

import org.eclipse.jface.text.IDocument;

import cybol_eclipse_plugin.Debug;
import cybol_eclipse_plugin.editor.dom.*;


import static cybol_eclipse_plugin.editor.Tokenizer.*;

/**
 * Diese Klasse ist zum Parsen von XSL-Dokumenten zuständig und splittet diese
 * in Token auf und erstellt daraus einen Dokumentenbaum, um auf einzelne
 * Elemente zugreifen zu können
 * 
 * @author Micha
 *
 */
public class XMLDocumentParser {
  
  
  private Tokenizer tokenizer = null;
  
  private IDocument doc = null;
  
  
  /**
   * enthält immer den aktuellen Knoten 
   */
  private Node cNode = null;
  
  /**
   * die folgenden Variablen beziehen sich immer auf die aktuellen geparsten Knoten
   * und werden genutzt, um Casts und <code>instanceof</code>-Operationen von 
   * <code>Node</code> zum jeweiligen Knotentyp zu reduzieren
   */
  private DocumentNode docNode = null;
  private TagNode tagNode = null;
  private ProcessInstructionNode piNode = null;
  private AttributeNode attrNode = null;
  
  /**
   * Beinhaltet das <code>Range</code>-Objekt zum aktuellen Element, dies ist nötig,
   * weil erst beim Lesen der schließenden spitzen Klammer das Ende des aktuellen
   * Elements bestimmt werden kann.
   */
  private Range currentElementRange = null;
  
  /**
   * Beinhaltet den Beginn des aktuellen Elements
   */
  private int elementBegin;
  
  
  /**
   * Erstellt einen <code>DocumentParser</code> ohne aktives Dokument.
   */
  public XMLDocumentParser() { }
  
  /**
   * Erstellt einen <code>DocumentParser</code> mithilfe eines
   * <code>IDocument</code>s.
   * 
   * @param doc zu parsendes XML-Dokument
   */
  public XMLDocumentParser(IDocument doc) {
    this.doc = doc;
  }
  
  
  public IDocument getDocument() {
    return doc;
  }
  
  public void setDocument(IDocument document) {
    doc = document;
  }
  
  
  /**
   * Beginnt mit dem parsen des XML-Dokuments.
   * 
   * @return Baumhierarchie des XML-Dokuments
   * @throws InvalidXMLDocumentException wenn Fehler auftreten
   */
  public DocumentNode parse() throws InvalidXMLDocumentException {
    
    if (doc != null) {
      
      String sheet = null;
      
      sheet = doc.get();
      
      if (sheet != null && sheet.length() > 0) {
        
        tokenizer = new Tokenizer(sheet);
        
        cNode = docNode = new DocumentNode();
        
        int currentToken;
        int lastToken = tokenizer.getLastToken();
        int index;
        String lastText;
        int textStart;
        
        // mit dem Parsen des Dokumentes beginnen
        while (true) {
          
          currentToken = tokenizer.getNextToken();
          index = tokenizer.getIndex();
          lastText = tokenizer.getLastText();
          textStart = tokenizer.getTextStart();
          
          if (Debug.SHOW_XML_TOKENS){
//          System.out.println(__debug__getConstName(lastToken) + " -> " + __debug__getConstName(currentToken));
            System.out.println(">> " + __debug__getConstName(currentToken));
          }
          
          switch (currentToken) {
            
            case TOKEN_OPEN:
              
              // Tag ist noch gar nicht richtig abgeschlossen
              if (lastToken == TOKEN_TAG_NAME        || lastToken == TOKEN_MISSING_ASSIGNMENT || 
                  lastToken == TOKEN_ATTRIBUTE_VALUE || lastToken == TOKEN_BROKEN_TAG_NAME) {
                
                currentElementRange.length = cNode.getName().length() + 1;
                cNode.putFlag(Node.MISSING_CLOSE);
                
                cNode = cNode.getParent();
                
              } else if (lastToken == TOKEN_BROKEN_ATTRIBUTE_VALUE) {
                
                attrNode.putFlag(Node.BROKEN_VALUE);
                
                currentElementRange.length = cNode.getName().length() + 1;
                cNode.putFlag(Node.MISSING_CLOSE);
                
                cNode = cNode.getParent();
                
              } else if (lastToken == TOKEN_DECLARATION || lastToken == TOKEN_PROCESSING_INSTRUCTION) {
                
                currentElementRange.length = cNode.getName().length() + 2;
                cNode.putFlag(Node.MISSING_CLOSE);
                
                tokenizer.setProcessingInstruction(false);
                
                cNode = cNode.getParent();
                
              } else if (lastToken == TOKEN_OPEN) {
                
                cNode = new UnknownNode(cNode, "<");
                cNode.setRange(new Range(elementBegin, 1));
                cNode = cNode.getParent();
                
              }
              
              // normal
              elementBegin = index - 1;
              
              break;
              
              
            case TOKEN_CLOSE:
              
              if (currentElementRange != null) {
                
                currentElementRange.length = index - elementBegin;
              }
              
              if (tokenizer.isProcessingInstruction()) {
                
                cNode.putFlag(Node.BROKEN_CLOSE);
                tokenizer.setProcessingInstruction(false);
                
                cNode = cNode.getParent();
              }
              
              break;
              
              
            case TOKEN_TAG_NAME:
            case TOKEN_BROKEN_TAG_NAME:
              
              cNode = tagNode = new TagNode(cNode, lastText, lastText.startsWith("xsl:"));
              cNode.setRange((currentElementRange = new Range(elementBegin)));
              
              break;
              
              
            case TOKEN_ATTRIBUTE_NAME:
              
              if (cNode == tagNode || cNode == piNode) {
                
                attrNode = new AttributeNode((AttributedNode) cNode, lastText);
                attrNode.setRange(new Range(index - lastText.length(), lastText.length()));
                
                attrNode.setAssignmentPosition(index);
              }
              
              break;
              
              
            case TOKEN_ATTRIBUTE_VALUE:
              
              attrNode.setValue(lastText);
              attrNode.setValueRange(new Range(textStart, lastText.length()));
              
              break;
              
              
            case TOKEN_TEXT:
              
              currentElementRange = null;
              
//              System.out.println("cNode: " + cNode);
              
              if (cNode == tagNode) {
                
                new TextNode(tagNode, lastText);
                
              } else if (cNode instanceof DocumentNode) {
                
                // prüfe, ob es nur whitespaces sind
                for (int i = 0; i < lastText.length(); i++) {
                  if (!Tokenizer.isWhiteSpace(lastText.charAt(i))) {
                    System.out.println("Fehler - Text darf nur Whitespaces enthalten");
                  }
                }
                  
                
              } else {
                // Fehler - Text nur zwischen Tags erlaubt
                System.out.println("Fehler - Text nur zwischen Tags erlaubt");
              }
              break;
              
              
            case TOKEN_CLOSING_TAG:
              
              // schießendes Tag stimmt genau mit dem letzten geöffneten überein
              if (lastText.equals(cNode.getName())) {
                
//                System.out.println("Closing Tag - Fall 1");
                tagNode.setSecondTagRange((currentElementRange = new Range(elementBegin)));
                
                cNode = cNode.getParent();
                
                if (cNode instanceof TagNode) {
                  
                  tagNode = (TagNode) cNode;
                  
//                } else {
//                  
//                  docNode = (DocumentNode) cNode;
                }
                
              } else {
                
                // schießendes Tag stimmt genau mit dem parent des letzten geöffneten Tags überein
                if (cNode.getParent() != null && lastText.equals(cNode.getParent().getName())) {
                  
//                  System.out.println("Closing Tag - Fall 2");
                  cNode.putFlag(Node.MISSING_CLOSE_TAG);
                  
                  // TODO - null-Prüfung?
                  ((TagNode) cNode.getParent()).setSecondTagRange((currentElementRange = new Range(elementBegin)));
                  cNode = cNode.getParent().getParent();
                  
                  if (cNode instanceof TagNode) {
                    
                    tagNode = (TagNode) cNode;
                  }
                  
                  // schließendes Tag passt nicht in den Baum und wird als Unknown deklariert
                } else {
                  
//                  System.out.println("Closing Tag - Fall 3");
                  
                  UnknownNode uNode = new UnknownNode(cNode, lastText);
                  uNode.putFlag(Node.WRONG_CLOSE_TAG);
                  uNode.setRange(currentElementRange = new Range(elementBegin));
                  
//                  tagNode.setSecondTagRange((currentElementRange = new Range(elementBegin)));
//                  tagNode.putFlag(Node.WRONG_CLOSE_TAG);
//                  
//                  cNode = cNode.getParent();
//                  
//                  if (cNode instanceof TagNode) {
//                    
//                    tagNode = (TagNode) cNode;
//                  }
//                  
//                  
//                  System.out.println("...schließende Tags...");
                }
                
                // Fehler - schließendes Tag stimmt nicht überein
                //throw new InvalidXMLDocumentException("Fehler - schließendes Tag stimmt nicht überein");
              }
              break;
              
              
            case TOKEN_EMPTY_TAG:
              
              cNode = cNode.getParent();
              
              if (cNode instanceof TagNode) {
                
                tagNode = (TagNode) cNode;
                
//              } else {
//                
//                docNode = (DocumentNode) cNode;
              }
              break;
              
              
            case TOKEN_COMMENT:
              
//              // TODO - wenn cNode == null, dann erstmal fest cNode = docNode setzen
//              if (cNode == null) {
//                cNode = docNode;
//              }
              
//              if (cNode == tagNode) {
                
                new CommentNode(cNode, lastText).setRange((currentElementRange = new Range(elementBegin)));
                
//              } else {
//                
//                // Fehler - Kommentare nur zwischen Tags erlaubt
//                
//                // TODO - Überprüfung ist definitiv falsch
//                // -> darf zum Beispiel auch zu Beginn einer Datei stehen
//                throw new InvalidXMLDocumentException("Fehler - Kommentare nur zwischen Tags erlaubt");
//              }
              break;
              
              
            case TOKEN_CDATA:
              
              if (cNode == tagNode) {
                
                new CDATANode(tagNode, lastText).setRange((currentElementRange = new Range(elementBegin)));
                
              } else {
                
                // Fehler - CDATA nur zwischen Tags erlaubt
                //throw new InvalidXMLDocumentException("Fehler - CDATA nur zwischen Tags erlaubt");
              }
              break;
              
              
            case TOKEN_DECLARATION:
              
              tokenizer.setProcessingInstruction(true);
              
              cNode = piNode = new ProcessInstructionNode(cNode, lastText);
              piNode.setRange((currentElementRange = new Range(elementBegin)));
              
              docNode.setDeclarationNode(piNode);
              
              
              break;
              
              
            case TOKEN_PROCESSING_INSTRUCTION:
              
              tokenizer.setProcessingInstruction(true);
              
//              if (cNode == tagNode) {
                
                cNode = piNode = new ProcessInstructionNode(cNode, lastText);
                piNode.setRange((currentElementRange = new Range(elementBegin)));
                
//              } else {
//                
//                // Fehler - Processing Instructions nur zwischen Tags erlaubt
//                throw new InvalidXMLDocumentException("Fehler - Process Instructions nur zwischen Tags erlaubt");
//              }
              break;
              
              
            case TOKEN_PROCESSING_INSTRUCTION_CLOSE:
              
              if (cNode == piNode) {
                
//                System.out.println("cNode: " + cNode);
                
                cNode = cNode.getParent();
                
//                System.out.println("cNode (parent): " + cNode);
                
                if (cNode instanceof TagNode) {
                  
                  tagNode = (TagNode) cNode;
                  
//                } else {
//                  
//                  docNode = (DocumentNode) cNode;
                }
                
              } else if (cNode != docNode) {
                
                throw new InvalidXMLDocumentException("Fehler - Fragezeichen sind an dieser Stelle nicht erlaubt");
              }
              tokenizer.setProcessingInstruction(false);
              
              break;
              
              
            case TOKEN_END_OF_FILE:
              
              // erstellte Baumstruktur validieren
              // weitere Bedingungen hinzufügen
              if (docNode == null) {
                
                // Fehler - Deklaration fehlt oder ist fehlerhaft
                throw new InvalidXMLDocumentException("Fehler - Deklaration fehlt oder ist fehlerhaft");
                
//              } else if (!"1.0".equals(docNode.getAttributeValue("version"))) {
//                
//                // Fehler - Fehlerhaftes Dokument
//                throw new InvalidXMLDocumentException("Fehler - Fehlerhaftes Dokument");
                
              } else {
                
                // ist eine Deklaration vorhanden?
                if (docNode.getDeclarationNode() != null) {
                  
                  piNode = docNode.getDeclarationNode();
                  
                  // steht die Deklaration direkt am Beginn?
                  if (piNode.getRange().begin != 0) {
                    piNode.putFlag(Node.BROKEN_DECLARATION_POSITION);
                  }
                  
                  String temp;
                  
                  if ((temp = piNode.getAttributeValue("version")) != null) {
                    
                    if (!temp.equals("1.0") && !temp.equals("1.1")) {
                      // TODO - es fehlt nicht, es ist ungültig
                      piNode.putFlag(Node.MISSING_VERSION_ATTRIBUTE);
                    }
                    
                  } else {
                    
                    piNode.putFlag(Node.MISSING_VERSION_ATTRIBUTE);
                  }
                  
                  // TODO - Encoding prüfen
                  
                } else {
                  
                  docNode.putFlag(Node.MISSING_DECLARATION);
                }
                
                // prüfen, ob genau ein Tag als Wurzel angegeben wurde
                int tagCounter = 0;
                
                for (Node node : docNode.getChildren()) {
                  if (node instanceof TagNode) {
                    tagCounter++;
                  }
                }
                
                if (tagCounter != 1) {
                  
                  System.out.println("als Wurzel darf genau nur ein Tag angegeben werden!");
                }
                
                // prüfen, ob alle Tags geschlossen wurden
                while (cNode != docNode) {
                  
                  cNode.putFlag(Node.MISSING_CLOSE_TAG);
                  cNode = cNode.getParent();
                }
                
                
//                System.out.println("cNode:  " + cNode.toString());
//                System.out.println("cLevel: " + cNode.getLevel());
                
                return docNode;
              }
              
              
            case TOKEN_UNEXPECTED_END:
              
              // Fehler - Unerwartetes Dokumentende
              if (cNode != null) {
                
                cNode.putFlag(Node.INAPPROPRIATE_END);
                
                // TODO - alle Fälle hinzufügen
                
                switch (lastToken) {
                  
                  case TOKEN_BROKEN_ATTRIBUTE_VALUE :
                    
                    attrNode.putFlag(Node.BROKEN_VALUE);
                    
                  case TOKEN_TAG_NAME :
                  case TOKEN_BROKEN_TAG_NAME :
                  case TOKEN_MISSING_ASSIGNMENT :
                  case TOKEN_ATTRIBUTE_VALUE :
                    
                    currentElementRange.length = cNode.getName().length() + 1;
                    cNode.putFlag(Node.MISSING_CLOSE);
                    
                    cNode = cNode.getParent();
                    
                    break;
                    
                  case TOKEN_DECLARATION :
                  case TOKEN_PROCESSING_INSTRUCTION :
                    
                    currentElementRange.length = cNode.getName().length() + 2;
                    cNode.putFlag(Node.MISSING_CLOSE);
                    
                    tokenizer.setProcessingInstruction(false);
                    
                    cNode = cNode.getParent();
                    
                    break;
                    
                  case TOKEN_OPEN :
                    
                    cNode = new UnknownNode(cNode, "<");
                    cNode.setRange(new Range(elementBegin, 1));
                    cNode = cNode.getParent();
                    
                    break;
                }
                
                return docNode;
                
              } else {
                
                System.out.println("- unerwartetes Ende - kein Knoten -");
                System.out.println("docNode: " + docNode);
                return docNode;
              }
              //throw new InvalidXMLDocumentException("Fehler - Unerwartetes Dokumentende");
              
              //break;
              
              
            case TOKEN_MISSING_TAG_NAME:
              
              cNode = tagNode = new TagNode(cNode, "");
              tagNode.setRange((currentElementRange = new Range(elementBegin)));
              tagNode.putFlag(Node.MISSING_NAME);
              
              break;
              
              
            case TOKEN_BROKEN_ATTRIBUTE_NAME:
              
              attrNode = new AttributeNode((AttributedNode) cNode, lastText);
              attrNode.setRange(new Range(index - lastText.length(), lastText.length()));
              attrNode.putFlag(Node.BROKEN_NAME);
              
              break;
              
              
            case TOKEN_MISSING_ASSIGNMENT:
              
              attrNode.putFlag(Node.MISSING_VALUE);
              
              break;
              
              
            case TOKEN_BROKEN_ATTRIBUTE_VALUE:
              
              attrNode.setValue(lastText);
              attrNode.setValueRange(new Range(textStart, lastText.length()));
              attrNode.putFlag(Node.BROKEN_VALUE);
              
              break;
              
              
            case TOKEN_BROKEN_PROCESSING_INSTRUCTION:
              
              UnknownNode uNode = new UnknownNode(cNode, lastText);
              uNode.setRange(new Range(elementBegin, index - elementBegin));
              uNode.putFlag(Node.BROKEN_PROCESSING_INSTRUCTION);
          }
          
          lastToken = currentToken;
        }
        
      } else {
        
        //throw new InvalidXMLDocumentException("Fehler - Inhalt des Dokuments fehlerhaft");
      }
    }
    
    //throw new InvalidXMLDocumentException("Fehler - Das Dokument darf nicht null sein");
    return null;
  }
  
  
  private String __debug__getConstName(int i) {
    
    switch (i) {
      
      case 0:
        return "TOKEN_UNEXPECTED_END               ";
      case 1:
        return "TOKEN_OPEN                         ";
      case 2:
        return "TOKEN_CLOSE                        ";
      case 3:
        return "TOKEN_DECLARATION                  ";
      case 4:
        return "TOKEN_TAG_NAME                     ";
      case 5:
        return "TOKEN_CLOSING_TAG                  ";
      case 6:
        return "TOKEN_EMPTY_TAG                    ";
      case 7:
        return "TOKEN_TEXT                         ";
      case 8:
        return "TOKEN_COMMENT                      ";
      case 9:
        return "TOKEN_CDATA                        ";
      case 10:
        return "TOKEN_ASSIGNMENT                   ";
      case 11:
        return "TOKEN_BEGIN_PARSING                ";
      case 12:
        return "TOKEN_ATTRIBUTE_NAME               ";
      case 13:
        return "TOKEN_ATTRIBUTE_VALUE              ";
      case 14:
        return "TOKEN_PROCESSING_INSTRUCTION       ";
      case 15:
        return "TOKEN_PROCESSING_INSTRUCTION_CLOSE ";
      case 16:
        return "TOKEN_END_OF_FILE                  ";
        
      case 20:
        return "TOKEN_MISSING_TAG_NAME             ";
      case 21:
        return "TOKEN_MISSING_ASSIGNMENT           ";
      case 22:
        return "TOKEN_MISSING_CLOSE                ";
        
      case 30:
        return "TOKEN_BROKEN_TAG_NAME              ";
      case 31:
        return "TOKEN_BROKEN_ATTRIBUTE_NAME        ";
      case 32:
        return "TOKEN_BROKEN_CLOSING_TAG           ";
      case 33:
        return "TOKEN_BROKEN_PROCESSING_INSTRUCTION";
      case 34:
        return "TOKEN_BROKEN_ATTRIBUTE_VALUE       ";
        
      case 40:
        return "TOKEN_REPEATED_OPEN                ";
    }
    
    return null;
  }
}