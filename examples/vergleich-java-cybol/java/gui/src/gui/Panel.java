package gui;

import java.awt.Color;
import javax.swing.JButton;
import javax.swing.JPanel;

public class Panel extends JPanel {

	JButton worldButton;
	JButton cybopButton;

	public Panel() {

		this.worldButton = new JButton("Greet World");
		this.worldButton.setOpaque(true);
		this.worldButton.setBackground(Color.WHITE);
		this.worldButton.setForeground(Color.BLACK);
		this.worldButton.setActionCommand("greet-world");

		this.cybopButton = new JButton("Greet CYBOP");
		this.cybopButton.setOpaque(true);
		this.cybopButton.setBackground(Color.WHITE);
		this.cybopButton.setForeground(Color.BLACK);
		this.cybopButton.setActionCommand("greet-cybop");

		add(this.worldButton);
		add(this.cybopButton);
	}
}
