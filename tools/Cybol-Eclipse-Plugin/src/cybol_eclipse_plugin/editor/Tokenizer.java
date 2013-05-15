package cybol_eclipse_plugin.editor;


public final class Tokenizer {
  
  public final static char EOF = 0;
  
  /* Tokens */
  public final static int TOKEN_UNEXPECTED_END = 0;
  public final static int TOKEN_OPEN = 1;
  public final static int TOKEN_CLOSE = 2;
  public final static int TOKEN_DECLARATION = 3;
  public final static int TOKEN_TAG_NAME = 4;
  public final static int TOKEN_CLOSING_TAG = 5;
  public final static int TOKEN_EMPTY_TAG = 6;
  public final static int TOKEN_TEXT = 7;
  public final static int TOKEN_COMMENT = 8;
  public final static int TOKEN_CDATA = 9;
  // private final static int TOKEN_ASSIGNMENT = 10;
  public final static int TOKEN_BEGIN_PARSING = 11;
  public final static int TOKEN_ATTRIBUTE_NAME = 12;
  public final static int TOKEN_ATTRIBUTE_VALUE = 13;
  public final static int TOKEN_PROCESSING_INSTRUCTION = 14;
  public final static int TOKEN_PROCESSING_INSTRUCTION_CLOSE = 15;
  public final static int TOKEN_END_OF_FILE = 16;
  
  public final static int TOKEN_MISSING_TAG_NAME = 20;
  public final static int TOKEN_MISSING_ASSIGNMENT = 21;
  public final static int TOKEN_MISSING_CLOSE = 22;
  
  public final static int TOKEN_BROKEN_TAG_NAME = 30;
  public final static int TOKEN_BROKEN_ATTRIBUTE_NAME = 31;
  public final static int TOKEN_BROKEN_CLOSING_TAG = 32;
  public final static int TOKEN_BROKEN_PROCESSING_INSTRUCTION = 33;
  public final static int TOKEN_BROKEN_ATTRIBUTE_VALUE = 34;
  
//  public final static int TOKEN_REPEATED_OPEN = 40;
  
  
  private char[] content = null;
  
  
  /**
   * aktuelle Position im zu parsenden Dokument während der Ausführung zeigt
   * <code>index</code> immer auf das nächste Zeichen, was nicht mehr zum
   * aktuellen Token gehört
   */
  private int index = -1;
  
  
  private int textStart = -1;
  
  
  /**
   * speichert den zuletzt geparsten Token
   */
  private int lastToken = TOKEN_UNEXPECTED_END;
  
  
  /**
   * speichert den textlichen Inhalt des letzten Tokens
   */
  private String lastText = null;
  
  
  /**
   * Dieses Flag wird benötigt, um der Funktion <code>getNextToken</code> zu
   * sagen, dass das nächste Element auf '?>' statt '>' enden muss.
   */
  private boolean isProcessingInstruction = false;
  
  
  public Tokenizer(String doc) {
    
    content = new char[doc.length() + 1];
    System.arraycopy(doc.toCharArray(), 0, content, 0, doc.length());
    content[doc.length()] = EOF;
    
    lastToken = TOKEN_BEGIN_PARSING;
    
    index = 0;
  }
  
  
  /**
   * Liest den nächsten Token aus dem XSL-Dokument aus und setzt
   * <code>lastText</code>, falls der Token einen textuellen Kontext besitzt.
   * 
   * @return den zuletzt gelesenen Token
   */
  public int getNextToken() throws InvalidXMLDocumentException {
    
    return lastToken = findNextToken();
  }
  
  
  private int findNextToken() throws InvalidXMLDocumentException {
    
    char c;
    
    // die Art des nächsten Tokens ist auch vom vorhergehenden abhängig und muss
    // an dieser Stelle berücksichtigt werden
    
    switch (lastToken) {
    
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////// TOKEN_CLOSE
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_CLOSE :
//      case TOKEN_MISSING_TAG_NAME :
      case TOKEN_BROKEN_PROCESSING_INSTRUCTION :
      case TOKEN_BEGIN_PARSING :
        
        if (content[index] == '<') {
          
          index++;
          return TOKEN_OPEN;
          
        } else if (content[index] == EOF) {
          
          return TOKEN_END_OF_FILE;
          
        } else {
          
          textStart = index;
          
          // index dekrementieren, weil sonst ein Zeichen überlesen werden würde
          index--;
          
          while ((c = content[++index]) != EOF) {
            
            if (c == '<') {
              
              lastText = extractText();
              
              return TOKEN_TEXT;
            }
          }
          
          if (textStart < index) {
            
            lastText = extractText();
            
            return TOKEN_TEXT;
          }
          
          // Ende der Datei erreicht,
          return TOKEN_END_OF_FILE;
        }
        
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // /////////////////////////////////////////////// TOKEN_OPEN
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_OPEN :
        
        c = content[index];
        
        if (c == '/') {
          
          textStart = ++index;
          
          if (isNameBegin(content[index])) {
            
            while ((c = content[++index]) != EOF) {
              
              if (!isName(c)) {
                
                lastText = extractText();
                
                return TOKEN_CLOSING_TAG;
              }
            }
            
            lastText = extractText();
            
            return TOKEN_BROKEN_CLOSING_TAG;
            
          } else if (isWhiteSpace(content[index])) {
            
            // TODO - fehlerhaftes End-Tag
            /*
             * // Fehler - Name des schließenden Tags erwartet return
             * TOKEN_MISSING_TAG_NAME;
             * 
             * } else {
             * 
             * // Fehler - Ungültiger Name für Tag return TOKEN_BROKEN_TAG_NAME;
             */
          }
          
        } else if (c == '!') {
          
          if (content[index + 1] == '-' && content[index + 2] == '-') {
            
            index += 2;
            
            textStart = index + 1;
            
            while ((c = content[++index]) != EOF) {
              
              if (c == '-' && content[index + 1] == '-'
                  && content[index + 2] == '>') {
                
                lastText = extractText();
                
                index += 2;
                return TOKEN_COMMENT;
                
              }
            }
            
          } else if (content[index + 1] == '[' && content[index + 2] == 'C'
              && content[index + 3] == 'D' && content[index + 4] == 'A'
              && content[index + 5] == 'T' && content[index + 6] == 'A'
              && content[index + 7] == '[') {
            
            index += 7;
            
            textStart = index + 1;
            
            while ((c = content[++index]) != EOF) {
              
              if (c == ']' && content[index + 1] == ']'
                  && content[index + 2] == '>') {
                
                lastText = extractText();
                
                index += 2;
                return TOKEN_CDATA;
                
              }
            }
            
          } else {
            
            // Fehler - DTD noch nicht implementiert
            throw new InvalidXMLDocumentException("Fehler - DTD noch nicht implementiert");
          }
          
        } else if (c == '?') {
          
          if (content[index + 1] == 'x' && content[index + 2] == 'm' && content[index + 3] == 'l') {
            
            lastText = "xml";
            
            index += 4;
            return TOKEN_DECLARATION;
            
          } else if (isNameBegin(content[++index])) {
            
            textStart = index;
            
            while ((c = content[++index]) != EOF) {
              
              if (!isName(c)) {
                
                if (isWhiteSpace(c) || c == '?') {
                  
                  lastText = extractText();
                  
                  return TOKEN_PROCESSING_INSTRUCTION;
                  
                } else {
                  
                  // TODO - fehlerhaftes PI-TAG
                  // Fehler - unerlaubtes Zeichen
                  throw new InvalidXMLDocumentException(
                      "Fehler - Attribut oder Ende der Verarbeitungsanweisung erwartet");
                }
              }
            }
            
            lastText = extractText();
            
            // Fehler - Processing Instruction beginnt und endet plötzlich durch
            // EOF
            return TOKEN_BROKEN_PROCESSING_INSTRUCTION;
            
          } else {
            
            lastText = "";
            
            // man könnte hier ähnlich vorgehen wie bei kaputten Tags, 
            // aber momentan einfach als broken definiert
            return TOKEN_BROKEN_PROCESSING_INSTRUCTION;
          }
          
        } else if (isNameBegin(c)) {
          
          textStart = index;
          
          while ((c = content[++index]) != EOF) {
            
            if (!isName(c)) {
              
              if (isWhiteSpace(c) || c == '>' || c == '/') {
                
                lastText = extractText();
                
                return TOKEN_TAG_NAME;
                
              } else {
                
                lastText = extractText();
                
                // Fehler - unerlaubtes Zeichen
                return TOKEN_BROKEN_TAG_NAME;
              }
            }
          }
          
          lastText = extractText();
          
          // Fehler - TagName beginnt und endet plötzlich durch EOF
          return TOKEN_BROKEN_TAG_NAME;
          
        } else {
          
          ignoreWhitespaces();
          
          if (content[index] == '<') {
            
            // neues Tag folgt direkt auf '<', kaputtes Tag ignorieren
            index++;
            return TOKEN_OPEN;
            
          } else if (content[index] != EOF) {
            
            textStart = index;
            
            while ((c = content[++index]) != EOF) {
              
              if (isWhiteSpace(c) || c == '>' || c == '/') {
                
                lastText = extractText();
                
                // Fehler - Tag-Name enthält ungültige Zeichen
                return TOKEN_BROKEN_TAG_NAME;
              }
            }
          }
        }
        break;
      
      // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      // /////////////////////////////////////////////// TOKEN_DECLARATION
      // TOKEN_TAG_NAME TOKEN_ATTRIBUTE_VALUE
      // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_DECLARATION :
      case TOKEN_TAG_NAME :
      case TOKEN_ATTRIBUTE_VALUE :
      case TOKEN_PROCESSING_INSTRUCTION :
      case TOKEN_MISSING_ASSIGNMENT :
      case TOKEN_BROKEN_ATTRIBUTE_VALUE :
        
        // überprüfen, ob wenigstens ein Whitespace existiert
        if (ignoreWhitespaces()) {
          
          textStart = index;
          
          if (isNameBegin(content[index])) {
            
            while ((c = content[++index]) != EOF) {
              
              if (!isName(c)) {
                
                // schaue, ob das nächste Zeichen '=' ist, sonst sammele die
                // folgenden Zeichen
                // und füge sie zu einem ungültigen Attribute-Name zusammen
                if (c == '=' || isWhiteSpace(c)) {
                  
                  lastText = extractText();
                  
                  return TOKEN_ATTRIBUTE_NAME;
                }
                
                index--;
                
                while ((c = content[++index]) != EOF) {
                  
                  if (c == '=' || c == '/' || c == '>' || c == '<' || c == '?') {
                    
                    // Fehler - neues Token gefunden, gesammelte Zeichen nun als
                    // ungültigen Attribut-Namen interpretieren
                    lastText = extractText();
//                    System.out.println("lastText = " + lastText + "(" + c + ")");
                    
                    return TOKEN_BROKEN_ATTRIBUTE_NAME;
                  }
                }
                break;
              }
            }
            
            // Fehler - Attribut beginnt und endet plötzlich durch EOF
            lastText = extractText();
            
            return TOKEN_BROKEN_ATTRIBUTE_NAME;
          }
        }
        
        c = content[index];
        
//        if (!isProcessingInstruction && c == '>') {
        if (c == '>') {
          
          index++;
          return TOKEN_CLOSE;
          
        } else if (c == '/') {
          
          index++;
          return TOKEN_EMPTY_TAG;
          
          // evtl. muss man hier zwischen Process Instruction und Deklaration
          // unterscheiden
        } else if (isProcessingInstruction && c == '?') {
          
          index++;
          return TOKEN_PROCESSING_INSTRUCTION_CLOSE;
          
        } else if (c != EOF) {
          
          // Fehler - ungültiges Zeichen - versuche Fehler zu ignorieren
          if (content[index] == '<') {
            
            index++;
            return TOKEN_OPEN;
            
          } else {
            
            textStart = index;
            
            while ((c = content[++index]) != EOF) {
              
              if (isWhiteSpace(c) || c == '=') {
                
                lastText = extractText();
                
                return TOKEN_BROKEN_ATTRIBUTE_NAME;
              }
            }
            
            lastText = extractText();
            
            return TOKEN_BROKEN_ATTRIBUTE_NAME;
          }
        }
        
        break;
      
      // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      // /////////////////////////////////////////////// TOKEN_ATTRIBUTE_NAME
      // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_ATTRIBUTE_NAME :
      case TOKEN_BROKEN_ATTRIBUTE_NAME :
        
        // index dekrementieren, weil sonst ein Zeichen überlesen werden würde
        index--;
        
        // Whitespaces ignorieren
        while (isWhiteSpace(content[++index])) {
        }
        
        if (content[index] == '=') {
          
          // Whitespaces ignorieren
          while (isWhiteSpace(content[++index])) {
          }
          
          // muss entweder »"« oder »'« sein und wird gebraucht, weil es
          // mit dem schließenden Zeichen übereinstimmen muss
          char text_separator_char = content[index];
          
          if (text_separator_char == '"' || text_separator_char == '\'') {
            
            textStart = index + 1;
            
            while ((c = content[++index]) != EOF) {
              
              if (c == text_separator_char) {
                
                lastText = extractText();
                
                index++;
                return TOKEN_ATTRIBUTE_VALUE;
                
                // } else if (c == '<') {
                //
                // // Fehler - Zeichen nicht erlaubt
                // throw new
                // InvalidXMLDocumentException("Fehler - Zeichen nicht erlaubt");
              }
            }
            
            lastText = extractText();
            
//            index++;
            return TOKEN_BROKEN_ATTRIBUTE_VALUE;
            
          } else {
            
            // Fehler - Text in Anführungszeichen erwartet
            // throw new
            // InvalidXMLDocumentException("Fehler - Text in Anführungszeichen erwartet");
            
            textStart = index--;
            
            // TODO - mal evtl. genauer anschauen - ist wahrscheinlich nicht komplett OK so
            while ((c = content[++index]) != EOF) {
              
              if (c == ' ' || c == '<' || c == '?') {
                break;
              }
            }
            
            lastText = extractText();
            
            return TOKEN_BROKEN_ATTRIBUTE_VALUE;
          }
          
        } else {
          
          // Fehler - Zuweisung erwartet
          return TOKEN_MISSING_ASSIGNMENT;
        }
        
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // /////////////////////////////////////////////// TOKEN_ASSIGNMENT
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /*
         * case TOKEN_ASSIGNMENT:
         * 
         * // index dekrementieren, weil sonst ein Zeichen überlesen werden
         * würde index--;
         * 
         * // Whitespaces ignorieren while (isWhiteSpace(content[++index])) { }
         * 
         * // muss entweder »"« oder »'« sein und wird gebraucht, weil es // mit
         * dem schließenden Zeichen übereinstimmen muss char text_separator_char
         * = content[index];
         * 
         * if (text_separator_char == '"' || text_separator_char == '\'') {
         * 
         * int start_attribute_value = index + 1;
         * 
         * while ((c = content[++index]) != EOF) {
         * 
         * if (c == text_separator_char) {
         * 
         * lastText = new String(content, start_attribute_value, index -
         * start_attribute_value);
         * 
         * index++; return TOKEN_ATTRIBUTE_VALUE;
         * 
         * // } else if (c == '<') { // // // Fehler - Zeichen nicht erlaubt //
         * throw new
         * InvalidXMLDocumentException("Fehler - Zeichen nicht erlaubt"); // } }
         * 
         * lastText = new String(content, start_attribute_value, index -
         * start_attribute_value);
         * 
         * index++; return TOKEN_BROKEN_ATTRIBUTE_VALUE;
         * 
         * } else {
         * 
         * // Fehler - Text in Anführungszeichen erwartet //throw new
         * InvalidXMLDocumentException
         * ("Fehler - Text in Anführungszeichen erwartet");
         * 
         * index--;
         * 
         * int start_attribute_value = index + 1;
         * 
         * // TODO - mal evtl. genauer anschauen - ist wahrscheinlich nich
         * komplett OK so while ((c = content[++index]) != EOF) {
         * 
         * if (c == ' ' || c == '<') {
         * 
         * lastText = new String(content, start_attribute_value, index -
         * start_attribute_value);
         * 
         * index++; return TOKEN_ATTRIBUTE_VALUE;
         * 
         * } } break; }
         */
        
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // /////////////////////////////////////////////// TOKEN_CLOSING_TAG
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_CLOSING_TAG :
        
        ignoreWhitespaces();
        
        if (content[index] == '>') {
          
          index++;
          return TOKEN_CLOSE;
          
        } else {
          
          // Fehler - ungültiges Zeichen
          throw new InvalidXMLDocumentException("Fehler - ungültiges Zeichen");
        }
        
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // /////////////////////////////////////////////// TOKEN_TEXT
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_TEXT :
        
        if (content[index] == '<') {
          
          index++;
          return TOKEN_OPEN;
          
        } else {
          
          // Fehler - ungültiges Zeichen
          throw new InvalidXMLDocumentException("Fehler - ungültiges Zeichen");
        }
        
      case TOKEN_EMPTY_TAG :
      case TOKEN_COMMENT :
      case TOKEN_CDATA :
        
        if (content[index] == '>') {
          
          index++;
          return TOKEN_CLOSE;
          
        } else {
          
          // Fehler - ungültiges Zeichen
          throw new InvalidXMLDocumentException("Fehler - Ungültiges Zeichen");
        }
        
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // ///////////////////////////////////////////////
        // TOKEN_PROCESSING_INSTRUCTION_CLOSE
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case TOKEN_PROCESSING_INSTRUCTION_CLOSE :
        
        if (content[index] == '>') {
          
          index++;
          return TOKEN_CLOSE;
          
        } else {
          
          return TOKEN_MISSING_CLOSE;
//          throw new InvalidXMLDocumentException("Fehler - Schließende spitze Klammer erwartet");
        }
        
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // /////////////////////////////////////////////// TOKEN_BEGIN_PARSING
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      case TOKEN_BEGIN_PARSING :
//        
//        if (content[index] == '<') {
//          
//          index++;
//          return TOKEN_OPEN;
//          
//        } else {
//          
//          // Fehler - Dokument muss mit Deklaration beginnen
//          throw new InvalidXMLDocumentException(
//              "Fehler - Dokument muss mit Deklaration beginnen");
//        }
        
      case TOKEN_MISSING_TAG_NAME :
        
        ignoreWhitespaces();
        
        if (isNameBegin(content[index])) {
          
          textStart = index;
          
          while ((c = content[++index]) != EOF) {
            
            if (!isName(c)) {
              
              lastText = extractText();
              
              return TOKEN_ATTRIBUTE_NAME;
            }
          }
          
        } else if (content[index] == '<') {
          
          index++;
          return TOKEN_OPEN;
          
        } else if (content[index] == '>') {
          
          index++;
          return TOKEN_CLOSE;
          
        } else {
          
          textStart = index;
          
          while ((c = content[++index]) != EOF) {
            
            if (isWhiteSpace(c)) {
              
              lastText = extractText();
              
              return TOKEN_BROKEN_ATTRIBUTE_NAME;
            }
          }
        }
    }
    
    return TOKEN_UNEXPECTED_END;
  }
  
  
  /**
   * Überprüft, ob es sich bei einem Zeichen um ein gültiges Zeichen innerhalb
   * eines Names handelt.
   * 
   * @param c
   *          - das zu überprüfende Zeichen
   * @return - <code>true</code>, falls dieses Zeichen innerhalb eines Namens
   *         verwendet werden darf
   */
  private static boolean isName(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9'
        || c == 'ä' || c == 'ö' || c == 'ü' || c == 'Ä' || c == 'Ö' || c == 'Ü'
        || c == '_' || c == '-' || c == ':' || c == '.';
  }
  
  
  /**
   * Überprüft, ob es sich bei einem Zeichen um ein gültiges Zeichen für den
   * Beginn von Namen handelt.
   * 
   * @param c
   *          - das zu überprüfende Zeichen
   * @return - <code>true</code>, falls es ein gültiges Zeichen für den Beginn
   *         eines Namens ist
   */
  private static boolean isNameBegin(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == 'ä' || c == 'ö'
        || c == 'ü' || c == 'Ä' || c == 'Ö' || c == 'Ü' || c == '_';
  }
  
  
  /**
   * Überprüft, ob es sich bei einem Zeichen um ein Whitespace handelt.
   * 
   * @param c
   *          - das zu überprüfende Zeichen
   * @return - <code>true</code>, falls es ein Whitespace ist, sonst
   *         <code>false</code>
   */
  public static boolean isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
  }
  
  
  /**
   * Diese Methode liest solange, bis es auf ein Zeichen trifft, welches kein
   * Whitespace ist.
   * 
   * @return - liefert <code>true</code>, wenn wenigstens ein Whitespace
   *         übersprungen wurde, sonst <code>false</code>
   */
  private boolean ignoreWhitespaces() {
    
    if (isWhiteSpace(content[index])) {
      
      while (isWhiteSpace(content[++index])) { }
      
      return true;
    }
    
    return false;
  }
  
  
  private String extractText() {
    return new String(content, textStart, index - textStart);
  }
  
  
  public String getLastText() {
    return lastText;
  }
  
  
  public int getTextStart() {
    return textStart;
  }
  
  
  public int getIndex() {
    return index;
  }
  
  
  public int getLastToken() {
    return lastToken;
  }
  
  
  public boolean isProcessingInstruction() {
    return isProcessingInstruction;
  }
  
  public void setProcessingInstruction(boolean isProcessingInstruction) {
    this.isProcessingInstruction = isProcessingInstruction;
  }
}