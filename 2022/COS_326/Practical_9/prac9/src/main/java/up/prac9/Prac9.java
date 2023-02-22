/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package up.prac9;

import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoIterable;
import static com.mongodb.client.model.Aggregates.match;
import static com.mongodb.client.model.Aggregates.project;
import static com.mongodb.client.model.Aggregates.unwind;
import static com.mongodb.client.model.Filters.eq;
import static com.mongodb.client.model.Filters.in;
import static com.mongodb.client.model.Filters.or;
import static com.mongodb.client.model.Filters.regex;
import static com.mongodb.client.model.Filters.text;
import com.mongodb.client.model.Projections;

import static java.util.Arrays.asList;
import java.util.function.Consumer;
import org.bson.Document;
import org.bson.conversions.Bson;

import java.util.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.persistence.*;
import javax.swing.*;
import java.io.*;
import java.util.Vector;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumnModel;
import javax.swing.table.TableModel;
import javax.swing.table.TableRowSorter;

/**
 *
 * @author Dylan Kapnias (u18108467)
 */
public class Prac9 {
    
    public static void print(String s) {
        System.out.println(s);
    }
    
    public static void add(Document d) {
                // c.ii
        MongoClient client = (MongoClient) MongoClients.create("mongodb://localhost:27017");
        MongoDatabase database = client.getDatabase("prac9db");
      
        MongoCollection<Document> dataMess = database.getCollection("messages");
        
        dataMess.insertOne(d);
    }
    
    public static JFrame createGUI(MongoDatabase database) {
        JFrame mainFrame = new JFrame();

        JPanel mainPanel = new JPanel();
        mainPanel.setBorder(BorderFactory.createEmptyBorder(30, 30, 10, 30));
        mainPanel.setLayout(new GridLayout(1, 1));
        
        JTabbedPane tabs = new JTabbedPane();

        tabs.addTab("Prac9", createTab(database));
        
        mainPanel.add(tabs);

        mainFrame.add(mainPanel, BorderLayout.CENTER);
        mainFrame.setVisible(true);
        //mainFrame.pack();
        mainFrame.setSize(1000, 500);
        mainFrame.setTitle("COS326_Prac1");
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        return mainFrame;
    }
    
    public static JPanel createTab(MongoDatabase database) {
        Vector<String> c = new Vector<>();
        c.add("Insert Student Number");
        c.add("Insert Student First Name");
        c.add("Insert Student Last Name");
        c.add("Insert Student Degree");

        JPanel control = new JPanel();
        control.setLayout(new GridLayout(1, 4));

        JButton lB = new JButton("Get Collection Names");
        control.add(lB);
        lB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p = new JPanel();
                p.setLayout(new GridLayout(3, 1));
                
                MongoIterable<String> list = database.listCollectionNames();
                for (String name : list) {
                   p.add(new JLabel(name));
                }

                JButton cButton = new JButton("Close");
                p.add(cButton, BorderLayout.SOUTH);

                Popup pop = new PopupFactory().getPopup(control, p, 100, 100);

                cButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });

                pop.show();
            }
        });

        JButton aB = new JButton("Get array docs");
        control.add(aB);
        aB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(3, 1));
                
                Bson pF = Projections.fields(
                Projections.excludeId(),
                Projections.include("data"));
        
                database.getCollection("facebook").aggregate(asList(
                        unwind("$data"),
                        project(pF))).forEach((Consumer<Document>)doc -> {
                            Document newDoc = (Document)doc.get("data");
                            p1.add(new JLabel(newDoc.toJson()));
                        });
                
                JButton addButton1 = new JButton("Close");
                p1.add(addButton1, BorderLayout.SOUTH);

                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                addButton1.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });
            }
        });

        JButton uB = new JButton("Count");
        control.add(uB);
        uB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(2, 1));
                JLabel l1 = new JLabel("0");
                p1.add(l1);
                
                Bson pF = Projections.fields(
                Projections.excludeId(),
                Projections.include("data.message"));
        
                database.getCollection("facebook").aggregate(asList(
                        unwind("$data"),
                        project(pF))).forEach((Consumer<Document>)doc -> {
                            int count = Integer.parseInt(l1.getText());
                            l1.setText(String.valueOf(++count));
                        });
                
                JButton upButton1 = new JButton("Close");
                p1.add(upButton1, BorderLayout.SOUTH);
                
                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                upButton1.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });
            }
        });

        JButton dB = new JButton("Count Spring");
        control.add(dB);
        dB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(2, 1));
                JLabel l1 = new JLabel("0");
                p1.add(l1);
                
                Bson pF = Projections.fields(
                Projections.excludeId(),
                Projections.include("data.message"));
        
                database.getCollection("facebook").aggregate(asList(
                        unwind("$data"),
                        project(pF),
                        match(or(regex("data.message", "September"), regex("data.message", "spring"))))).forEach((Consumer<Document>)doc -> {
                            int count = Integer.parseInt(l1.getText());
                            l1.setText(String.valueOf(++count));
                        });
                
                JButton delButton1 = new JButton("Close");
                p1.add(delButton1, BorderLayout.SOUTH);

                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                delButton1.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });
            }
        });

        return control;
    }

    public static void main(String[] args) {
        // c.i
        MongoClient client = (MongoClient) MongoClients.create("mongodb://localhost:27017");
        MongoDatabase database = client.getDatabase("prac9db");
        
        // c.ii 
        MongoCollection<Document> data = database.getCollection("facebook");
        
        Bson pF = Projections.fields(
                Projections.excludeId(),
                Projections.include("data"));
        
//        data.aggregate(asList(
//                unwind("$data"),
//                project(pF),
//                match(or(regex("data.message", "September"), regex("data.message", "spring"))))).forEach((Consumer<Document>)doc -> {
//                    print(doc.get("data").toString());
//                });
        
        JFrame mainGUI = createGUI(database);
    }
}
