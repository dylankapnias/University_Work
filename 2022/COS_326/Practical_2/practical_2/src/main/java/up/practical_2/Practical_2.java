/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package up.practical_2;

/**
 *
 * @author Dylan Kapnias (u18108467)
 */

import java.util.List;
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


public class Practical_2 {

    public static void main(String[] args) {    
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/COS326_Prac2.odb");
        EntityManager em = emf.createEntityManager();
        
        JFrame mainGUI = createGUI(em);
        

//        Practical p = doesExist(em, 1);
//        if (p == null) {
//            print("The Prac does not exist!!");
//            return;
//        }
//        Student s = p.getStudent();
//        
//        print("Name: " + s.getName());
//        displayPracs(em);
//        print(deletePrac(em, 1));
//        
//        print("Prac Name: " + p.getName());
//        print("Name: " + s.getName());
//        
//        displayPracs(em);
    }
    
    public static void print(String s) {
        System.out.println(s);
    }
    
    public static String createPrac(EntityManager em, String pName, String sName) {
        if (comboExist(em, pName, sName)) {
            return "This student is already doing this Practial";
        }
        
        em.getTransaction().begin();
        em.persist(new Practical(pName, new Student(sName)));
        em.getTransaction().commit();
        
        return "Practical with name: " + pName + " and student: " +
                sName + " has been created.";
    }
    
    public static boolean comboExist(EntityManager em, String pName, String sName) {
        TypedQuery<Practical> q = em.createQuery("SELECT p FROM Practical p", Practical.class);
        java.util.List<Practical> results = q.getResultList();
        
        for (Practical p : results) {
                if (p.getName().equals(pName) && p.getStudent().getName().equals(sName)) {
                    return true;
                }
            }
        
        return false;
    }
    
    public static String getStudentName(EntityManager em, String pName) {
        String sName = "Not Found!";
        
        TypedQuery<Practical> q = em.createQuery("SELECT p FROM Practical p", Practical.class);
        java.util.List<Practical> results = q.getResultList();
        
        for (Practical p : results) {
            if (p.getName().equals(pName)) {
                sName = p.getStudent().getName();
            }
        }
        
        return sName;
    }
    
    public static void displayPracs(EntityManager em) {
        TypedQuery<Practical> q = em.createQuery("SELECT p FROM Practical p", Practical.class);
        java.util.List<Practical> results = q.getResultList();
        
        if (results.isEmpty()) {
            print("No pracs found");
        }
        else {
            for (Practical p : results) {
                print(p.getID() + ". " + p.getName());
            }
        }
    }
    
    public static String deletePrac(EntityManager em, long id) {
        Practical p = doesExist(em, id);
        if (p == null) {
            return "Practical with ID: " + id + " does not exist";
        }
        
        em.getTransaction().begin();
        
        em.remove(p);
        
        em.getTransaction().commit();
        
        return "Practical with ID: " + id + " has been removed";
    }

    public static Practical doesExist(EntityManager em, long l) {
        Practical p = (Practical)em.find(Practical.class, l);
        
        return p;
    }
    
    public static boolean doesExist(EntityManager em, String s) {
        TypedQuery<Practical> q = em.createQuery("SELECT p FROM Practical p", Practical.class);
        java.util.List<Practical> results = q.getResultList();
        
        if (results.isEmpty()) {
            print("No pracs found");
            return false;
        }
        else {
            for (Practical p : results) {
                if (p.getName().equals(s)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    public static String deleteStudent(EntityManager em, String s) {
        TypedQuery<Practical> q = em.createQuery("SELECT p FROM Practical p", Practical.class);
        java.util.List<Practical> results = q.getResultList();
        
        boolean min = false;
        
        if (results.isEmpty()) {
            return ("No pracs found");
        }
        else {
            for (Practical p : results) {
                if (p.getStudent().getName().equals(s)) {
                    deletePrac(em, p.getID());
                    min = true;
                }
            }
            
            return min ? "All pracs for student: " + s + " have been deleted."
                    : " There were no pracs for this student";
        }
    }
    
    public static JFrame createGUI(EntityManager em) {
        JFrame mainFrame = new JFrame();

        JPanel mainPanel = new JPanel();
        mainPanel.setBorder(BorderFactory.createEmptyBorder(30, 30, 10, 30));
        mainPanel.setLayout(new GridLayout(1, 1));
        
        JTabbedPane tabs = new JTabbedPane();

        tabs.addTab("Students", createStuTab(em));
        
        mainPanel.add(tabs);

        mainFrame.add(mainPanel, BorderLayout.CENTER);
        mainFrame.setVisible(true);
        mainFrame.setSize(1000, 500);
        mainFrame.setTitle("COS326_Prac2");
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        return mainFrame;
    }
    
    public static JPanel createStuTab(EntityManager em) {
        Vector<String> c = new Vector<>();
        c.add("Insert Student Name");
        c.add("Insert Practical Name");

        JPanel control = new JPanel();
        control.setLayout(new GridLayout(1, 4));

        JButton aB = new JButton("Add Prac");
        control.add(aB);
        aB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(3, 2));

                JLabel labels[] = new JLabel[2];
                JTextField texts[] = new JTextField[2];

                for (int i = 0; i < 2; i++) {
                    labels[i] = new JLabel(c.get(i));
                    labels[i].setBounds(10, 10 * i, 35, 25);

                    texts[i] = new JTextField(20);
                    texts[i].setBounds(50, 10 * i, 20, 25);

                    p1.add(labels[i]);
                    p1.add(texts[i]);
                }
                JButton addButton = new JButton("Add");
                p1.add(addButton);
                
                JButton addButton1 = new JButton("Close");
                p1.add(addButton1);

                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                addButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        String msg = createPrac(em, texts[1].getText(), texts[0].getText());
                        pop.hide();
                        
                        JPanel p2 = new JPanel();
                        p2.setLayout(new GridLayout(3, 1));
                        
                        JLabel label1 = new JLabel(msg);
                        p2.add(label1);
                        JButton addButton2 = new JButton("Close");
                        p2.add(addButton2);
                        
                        Popup pop2 = new PopupFactory().getPopup(control, p2, 100, 100);
                        pop2.show();
                        
                        addButton2.addActionListener(new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                pop2.hide();
                            }
                        });
                    }
                });
                
                addButton1.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });
            }
        });

        JButton uB = new JButton("Show Students Pracs");
        control.add(uB);
        uB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {   
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(2, 2));

                JLabel labels[] = new JLabel[1];
                JTextField texts[] = new JTextField[1];

                for (int i = 0; i < 1; i++) {
                    labels[i] = new JLabel(c.get(i).replace("Insert", "Select"));
                    labels[i].setBounds(10, 10 * i + 1, 35, 25);

                    texts[i] = new JTextField(20);
                    texts[i].setBounds(50, 10 * i + 1, 20, 25);

                    p1.add(labels[i]);
                    p1.add(texts[i]);
                }
                JButton upButton = new JButton("Select");
                p1.add(upButton);
                
                JButton upButton1 = new JButton("Close");
                p1.add(upButton1);
                
                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                upButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                        JPanel p2 = new JPanel();
                        p2.setBounds(100, 100, 500, 500);
                        
                        JScrollPane jsp = createStuTable(em, texts[0].getText());

                        p2.add(jsp, BorderLayout.CENTER);

                        JButton cButton = new JButton("Close");
                        p2.add(cButton, BorderLayout.SOUTH);

                        Popup pop2 = new PopupFactory().getPopup(control, p2, 100, 100);

                        cButton.addActionListener(new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                pop2.hide();
                            }
                        });

                        pop2.show();
                    }
                });
                
                upButton1.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });
            }
        });

        JButton dB = new JButton("Delete Pracs");
        control.add(dB);
        dB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(2, 2));

                JLabel jL = new JLabel("Student Name to Delete");
                jL.setBounds(10, 10, 35, 25);
                JTextField jT = new JTextField(20);
                jT.setBounds(50, 10, 20, 25);
                p1.add(jL);
                p1.add(jT);

                JButton delButton = new JButton("Delete");
                p1.add(delButton);
                
                JButton delButton1 = new JButton("Close");
                p1.add(delButton1);

                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                delButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        String msg = deleteStudent(em, jT.getText());
                        pop.hide();
                        
                        JPanel p2 = new JPanel();
                        p2.setLayout(new GridLayout(3, 1));
                        
                        JLabel label1 = new JLabel(msg);
                        p2.add(label1);
                        JButton addButton2 = new JButton("Close");
                        p2.add(addButton2);
                        
                        Popup pop2 = new PopupFactory().getPopup(control, p2, 100, 100);
                        pop2.show();
                        
                        addButton2.addActionListener(new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                pop2.hide();
                            }
                        });
                    }
                });
                
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
    
    public static JScrollPane createStuTable(EntityManager em, String sName) {
        Vector<String> c = new Vector<>();
        Vector<Vector<String>> d = new Vector<>();
        Vector<String> data = new Vector<>();

        c.add("Practical Name");
        
        TypedQuery<Practical> q = em.createQuery("SELECT p FROM Practical p", Practical.class);
        java.util.List<Practical> results = q.getResultList();

        for (Practical p : results) {
            if (p.getStudent().getName().equals(sName)) {
                data.add(p.getName());
//                data.add(p.get_fname());

                d.add(new Vector<String>(data));
                data.clear();
            }
        }

        DefaultTableModel m = new DefaultTableModel(d, c);

        JTable t = new JTable(m);
        t.setShowGrid(true);
        t.setShowVerticalLines(true);

        JScrollPane s = new JScrollPane(t);
        s.setBounds(10, 30, 400, 400);

        return s;
    }
}
