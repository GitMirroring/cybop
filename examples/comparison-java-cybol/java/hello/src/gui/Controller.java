package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller implements ActionListener {
	
	Model model;
	View view;

	public void initialise(Model m, View v) {
		
		this.model = m;
		this.view = v;
	}	

	@Override
	public void actionPerformed(ActionEvent e) {
		
		String cmd = e.getActionCommand();

		if (cmd.equals("greet-world")) {
			
			this.view.box.setText(this.model.helloWorld);
			this.view.repaint();

		} else if (cmd.equals("greet-cybop")) {

			this.view.box.setText(this.model.helloCYBOP);
			this.view.repaint();
		}
	}
}
