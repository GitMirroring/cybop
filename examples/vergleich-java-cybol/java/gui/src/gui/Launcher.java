package gui;

public class Launcher {

	public static void main(String[] args) {
		
		Model m = new Model();
		View v = new View();
		Controller c = new Controller();
		
		v.initialise(c);
		c.initialise(m, v);

		// Display initial text
		v.panel.worldButton.doClick();
	}
}
