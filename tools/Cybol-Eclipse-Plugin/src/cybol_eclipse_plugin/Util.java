package cybol_eclipse_plugin;

import java.io.*;
import java.util.*;

import org.eclipse.swt.graphics.Image;

public final class Util {
  
  private static Map<String, Image> images;
  
  static {
    images = new HashMap<String, Image>();
  }
  
  
  private Util() { }
  
  
  public static Image getImage(String path) {
    
    Image image = images.get(path);
    
    if (image == null) {
      
      try {
        InputStream stream = Activator.getDefault().getBundle().getEntry(path).openStream();
        image = new Image(Activator.getDefault().getWorkbench().getDisplay(), stream);
        images.put(path, image);
        
      } catch (IOException ex) {
        ex.printStackTrace();
      }
    }
    
    return image;
  }
}
