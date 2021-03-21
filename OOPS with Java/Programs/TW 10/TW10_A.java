import javax.swing.*;
import java.awt.event.*;
import java.lang.*;
import java.awt.*;
import java.util.*;
class TW10_A{
    public static void main(String[]args){
        JFrame jf = new JFrame("A simple calculator");
        jf.setSize(800,600);
       
        JLabel fn = new JLabel("First number");
        JLabel sn = new JLabel("Second number");
        JTextField a = new JTextField("");
        JTextField b = new JTextField("");
        JButton add = new JButton("Add");
        JButton sub = new JButton("Subtract");
        JButton mul = new JButton("Multiply");
        JButton div = new JButton("Divide");
        JLabel resultLabel = new JLabel("Result is :");
        JTextField result = new JTextField("");
        // X Y WIDTH HEIGHT
        fn.setBounds(50,50,100,25);
        a.setBounds(150,50,150,25);
        sn.setBounds(320,50,100,25);
        b.setBounds(450,50,150,25);
        add.setBounds(150,100,70,25);
        sub.setBounds(250,100,70,25);
        mul.setBounds(350,100,70,25);
        div.setBounds(450,100,70,25);
        resultLabel.setBounds(50,150,100,50);
        result.setBounds(250,150,250,25);
        add.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                int x,y,z=0;
                x=Integer.parseInt(a.getText());
                y=Integer.parseInt(b.getText());
                z=x+y;
                String s = String.valueOf(z);
                result.setText(s);
            }
        });
        sub.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                int x,y,z=0;
                x=Integer.parseInt(a.getText());
                y=Integer.parseInt(b.getText());
                z=x-y;
                String s = String.valueOf(z);
                result.setText(s);
            }
        });
        mul.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                int x,y,z=0;
                x=Integer.parseInt(a.getText());
                y=Integer.parseInt(b.getText());
                z=x*y;
                String s = String.valueOf(z);
                result.setText(s);
            }
        });
        div.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                int x,y,z=0;
                x=Integer.parseInt(a.getText());
                y=Integer.parseInt(b.getText());
                z=x/y;
                String s = String.valueOf(z);
                result.setText(s);
            }
        });
        jf.add(fn);
        jf.add(sn);
        jf.add(a);
        jf.add(b);
        jf.add(add);
        jf.add(sub);
        jf.add(mul);
        jf.add(div);
        jf.add(resultLabel);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.add(result);
        jf.setLayout(null);
        jf.setVisible(true);
    }
}