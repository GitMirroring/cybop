package cybol_eclipse_plugin.completion;

import org.eclipse.swt.graphics.Image;

public final class CompletionEntry {
  
  private String name;
  private String description;
  private String template;
  private Image icon;
  
  
  public CompletionEntry(String name, String description, String template, Image icon) {
    
    this.name = name;
    this.description = description;
    this.template = template;
    this.icon = icon;
  }
  
  
  public String getName() {
    return name;
  }
  
  public String getDescription() {
    return description;
  }
  
  public String getTemplate() {
    return template;
  }
  
  public Image getIcon() {
    return icon;
  }
}
