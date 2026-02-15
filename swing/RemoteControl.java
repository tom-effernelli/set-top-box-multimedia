import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;
    
    private JTextArea textArea;
    private RemoteClient client;

    public RemoteControl() {
        setTitle("Remote Control");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        try {
            client = new RemoteClient("localhost", 3331);
        } catch (Exception e) {
            System.err.println("Erreur de connexion : " + e);
            JOptionPane.showMessageDialog(this, "Serveur introuvable !", "Erreur", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }

        textArea = new JTextArea(20, 50);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);


        Action playAction = new AbstractAction("Play") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nom = JOptionPane.showInputDialog(RemoteControl.this, "Media to play:");
                if (nom != null && !nom.isEmpty()) {
                    String response = client.send("PLAY " + nom);
                    textArea.append(">>> PLAY " + nom + "\n" + response + "\n\n");
                }
            }
        };

        Action displayAction = new AbstractAction("Display") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nom = JOptionPane.showInputDialog(RemoteControl.this, "Media to display:");
                if (nom != null && !nom.isEmpty()) {
                    String response = client.send("DISPLAY " + nom);
                    if (response != null) response = response.replace(';', '\n');
                    textArea.append(">>> DISPLAY " + nom + "\n" + response + "\n\n");
                }
            }
        };

        Action saveAction = new AbstractAction("Save") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String response = client.send("SAVE database.txt");
                textArea.append(">>> SAVE\n" + response + "\n\n");
            }
        };

        Action loadAction = new AbstractAction("Load") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String response = client.send("LOAD database.txt");
                textArea.append(">>> LOAD\n" + response + "\n\n");
            }
        };

        Action quitAction = new AbstractAction("Quit") {
            @Override
            public void actionPerformed(ActionEvent e) {
                client.send("QUIT");
                System.exit(0);
            }
        };

        JToolBar toolBar = new JToolBar();
        toolBar.add(loadAction);
        toolBar.add(saveAction);
        toolBar.addSeparator();
        toolBar.add(playAction);
        toolBar.add(displayAction);
        toolBar.addSeparator();
        toolBar.add(quitAction);

        add(toolBar, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);

        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new RemoteControl());
    }
}