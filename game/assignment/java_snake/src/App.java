import javax.swing.*;

public class App {
    public static void main(String[] args) throws Exception {
        
        int boardWidth = 600;
        int boardHeight = boardWidth;

        JFrame jFrame = new JFrame("Java Snake");
        jFrame.setVisible(true);
        jFrame.setSize(boardWidth, boardHeight);
        jFrame.setLocationRelativeTo(null);
        jFrame.setResizable(false);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        SnakeGame snakeGame = new SnakeGame(boardWidth, boardHeight);
        jFrame.add(snakeGame);
        jFrame.pack();
        snakeGame.requestFocus();

    }
}
