package com.example;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

public class TemperatureConverter extends JFrame {
    
    JTextField inputField;
    JLabel inputLabel, outputLabel;
    JComboBox fromOptions, toOptions;

    // Constructor
    public TemperatureConverter() {

        setTitle("Temperature Converter");
        setSize(300, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel panel = new JPanel(new GridLayout(5, 2, 10, 10));
        panel.setBorder(new EmptyBorder(20, 20, 20, 20)); // padding 20 pixels

        // Options
        JLabel fromLabel = new JLabel("From: ");
        fromOptions = new JComboBox<>(new String[] {"Celsius", "Reaumur", "Fahrenheit", "Kelvin"});
        JLabel toLabel = new JLabel("To: ");
        toOptions = new JComboBox<>(new String[] {"Celsius", "Reaumur", "Fahrenheit", "Kelvin"});

        // Form
        inputField = new JTextField();
        inputLabel = new JLabel("\u00B0");
        JButton convertButton = new JButton("Convert");
        outputLabel = new JLabel("\u00B0");
        JButton clearButton = new JButton("Clear");
        JButton exitButton = new JButton("Exit");

        panel.add(fromLabel);
        panel.add(fromOptions);
        panel.add(toLabel);
        panel.add(toOptions);
        panel.add(inputField);
        panel.add(inputLabel);
        panel.add(convertButton);
        panel.add(outputLabel);
        panel.add(clearButton);
        panel.add(exitButton);

        add(panel);

        convertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                convertTemperature();
            }
        });

        clearButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                inputField.setText("");
                inputLabel.setText("\u00B0");
                outputLabel.setText("\u00B0");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

    }

    private void convertTemperature() {
        double input = Double.parseDouble(inputField.getText());
        String from = (String) fromOptions.getSelectedItem();
        String to = (String) toOptions.getSelectedItem();
        double output = 0.0;

        if (from.equals("Celsius")) {
            switch (to) {
                case "Celsius":
                    output = input;
                    break;
                case "Reaumur":
                    output = input * 0.8;
                    break;
                case "Fahrenheit":
                    output = input * 1.8 + 32;
                    break;
                case "Kelvin":
                    output = input + 273.15;
                    break;
            }
        } else if (from.equals("Reaumur")) {
            switch (to) {
                case "Celsius":
                    output = input / 0.8;
                    break;
                case "Reaumur":
                    output = input;
                    break;
                case "Fahrenheit":
                    output = input * 2.25 + 32;
                    break;
                case "Kelvin":
                    output = input / 0.8 + 273.15;
                    break;
            }
        } else if (from.equals("Fahrenheit")) {
            switch (to) {
                case "Celsius":
                    output = (input - 32) / 1.8;
                    break;
                case "Reaumur":
                    output = (input - 32) / 2.25;
                    break;
                case "Fahrenheit":
                    output = input;
                    break;
                case "Kelvin":
                    output = (input - 32) / 1.8 + 273.15;
                    break;
            }
        } else if (from.equals("Kelvin")) {
            switch (to) {
                case "Celsius":
                    output = input - 273.15;
                    break;
                case "Reaumur":
                    output = (input - 273.15) * 0.8;
                    break;
                case "Fahrenheit":
                    output = (input - 273.15) * 1.8 + 32;
                    break;
                case "Kelvin":
                    output = input;
                    break;
            }
        }

        outputLabel.setText(String.format("%.2f \u00B0%s", output, to));
    }

    public static void main(String[] args) {
        TemperatureConverter frame = new TemperatureConverter();
        frame.setVisible(true);
    }
}
