package gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class View extends JFrame {

	JLabel heading;
	JLabel box;
	Panel panel;

	public View() {

		Font fh = new Font("Arial", Font.BOLD, 64);
		this.heading = new JLabel("Java Greeting Application");
		this.heading.setForeground(Color.GREEN);
		this.heading.setFont(fh);
		this.heading.setHorizontalAlignment(JLabel.CENTER);

		Font fb = new Font("Arial", Font.BOLD, 64);
		this.box = new JLabel("test");
		this.box.setOpaque(true);
		this.box.setBackground(Color.BLUE);
		this.box.setForeground(Color.YELLOW);
		this.box.setFont(fb);
		this.box.setHorizontalAlignment(JLabel.CENTER);

		this.panel = new Panel();

		add(this.heading, BorderLayout.NORTH);
		add(this.box, BorderLayout.CENTER);
		add(this.panel, BorderLayout.SOUTH);

		setTitle("Comparison Java-CYBOL");
		setLocation(100, 100);
		setSize(800, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	public void initialise(Controller c) {

		this.panel.worldButton.addActionListener(c);
		this.panel.cybopButton.addActionListener(c);
	}
}
