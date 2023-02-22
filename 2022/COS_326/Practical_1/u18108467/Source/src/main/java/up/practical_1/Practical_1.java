/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package up.practical_1;

/**
 *
 * @author Dylan Kapnias (u18108467)
 */

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

public class Practical_1 {

    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("$objectdb/db/COS326_Prac1.odb");
        EntityManager em = emf.createEntityManager();

        JFrame mainGUI = createGUI(em);
        
        //em.close();
        //emf.close();
    }
    
    public static String createStudent(EntityManager em, String f, String l, String d, String n) {
        if (!doesExist(em, n)) {
            em.getTransaction().begin();
            Student s = new Student(f, l, d, n);
            em.persist(s);
            em.getTransaction().commit();
            return "Student with student number: " + n + " has been created";
        } else {
            return "Student with student number: " + n + " already exists";
        }
    }
    
    public static boolean doesExist(EntityManager em, String n) {
        Student s = (Student)em.find(Student.class, n);
        
        return s != null;
    }
    
    public static java.util.List<Student> getStudents(EntityManager em) {
        TypedQuery<Student> q = em.createQuery("SELECT s FROM Student s", Student.class);
        java.util.List<Student> results = q.getResultList();
        
        return results;
    }
    
    public static void printAmountStudents(EntityManager em) {
        Query q = em.createQuery("SELECT COUNT(s) FROM Student s");
        System.out.println("Total Students: " + q.getSingleResult());
    }
    
    public static String updateStudent(EntityManager em, String f, String l, String d, String n) {
        if (!doesExist(em, n)) {
            return "Student with student number: " + n + " does not exist";
        }
        
        Student s = (Student)em.find(Student.class, n);
        
        em.getTransaction().begin();
        
        s.set_fname(f);
        s.set_lname(l);
        s.set_dname(d);
        
        em.getTransaction().commit();
        
        return "Student with student number: " + n + " has been updated";
    }
    
    public static String removeStudent(EntityManager em, String n) {
        if (!doesExist(em, n)) {
            return "Student with student number: " + n + " does not exist";
        }
        
        Student s = (Student)em.find(Student.class, n);
        
        em.getTransaction().begin();
        
        em.remove(s);
        
        em.getTransaction().commit();
        
        return "Student with student number: " + n + " has been removed";
    }
    
    public static JFrame createGUI(EntityManager em) {
        JFrame mainFrame = new JFrame();

        JPanel mainPanel = new JPanel();
        mainPanel.setBorder(BorderFactory.createEmptyBorder(30, 30, 10, 30));
        mainPanel.setLayout(new GridLayout(1, 1));
        
        JTabbedPane tabs = new JTabbedPane();

        tabs.addTab("Students", createStuTab(em));
        //tabs.addTab("Clients", createClientsTab(em));
        
        mainPanel.add(tabs);

        mainFrame.add(mainPanel, BorderLayout.CENTER);
        mainFrame.setVisible(true);
        //mainFrame.pack();
        mainFrame.setSize(1000, 500);
        mainFrame.setTitle("COS326_Prac1");
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        return mainFrame;
    }

    public static JScrollPane createStuTable(EntityManager em) {
        Vector<String> c = new Vector<>();
        Vector<Vector<String>> d = new Vector<>();
        Vector<String> data = new Vector<>();

        c.add("Student Number");
        c.add("First Name");
        c.add("Last Name");
        c.add("Degree");
        
        java.util.List<Student> students = getStudents(em);
        
        for (Student s : students) {
            data.add(s.get_sno());
            data.add(s.get_fname());
            data.add(s.get_lname());
            data.add(s.get_dname());
            
            d.add(new Vector<String>(data));
            data.clear();
        }

        DefaultTableModel m = new DefaultTableModel(d, c);

        JTable t = new JTable(m);
        t.setShowGrid(true);
        t.setShowVerticalLines(true);

        JScrollPane s = new JScrollPane(t);
        s.setBounds(10, 30, 400, 400);

        return s;
    }

    public static JPanel createStuTab(EntityManager em) {
        Vector<String> c = new Vector<>();
        c.add("Insert Student Number");
        c.add("Insert Student First Name");
        c.add("Insert Student Last Name");
        c.add("Insert Student Degree");

        JPanel control = new JPanel();
        control.setLayout(new GridLayout(1, 4));

        JButton lB = new JButton("List");
        control.add(lB);
        lB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p = new JPanel();
                //p.setLayout(new BorderLayout());
                p.setBounds(100, 100, 500, 500);

                p.add(createStuTable(em), BorderLayout.CENTER);

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

        JButton aB = new JButton("Add");
        control.add(aB);
        aB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(5, 2));

                JLabel labels[] = new JLabel[4];
                JTextField texts[] = new JTextField[4];

                for (int i = 0; i < 4; i++) {
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
                        String msg = createStudent(em, texts[1].getText(), texts[2].getText(), texts[3].getText(), texts[0].getText());
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

        JButton uB = new JButton("Update");
        control.add(uB);
        uB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(6, 2));

                JLabel labels[] = new JLabel[4];
                JTextField texts[] = new JTextField[4];

                for (int i = 0; i < 4; i++) {
                    labels[i] = new JLabel(c.get(i).replace("Insert", "Update"));
                    labels[i].setBounds(10, 10 * i + 1, 35, 25);

                    texts[i] = new JTextField(20);
                    texts[i].setBounds(50, 10 * i + 1, 20, 25);

                    p1.add(labels[i]);
                    p1.add(texts[i]);
                }
                JButton upButton = new JButton("Update");
                p1.add(upButton);
                
                JButton upButton1 = new JButton("Close");
                p1.add(upButton1);
                
                Popup pop = new PopupFactory().getPopup(control, p1, 100, 100);
                pop.show();
                
                upButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        String msg = updateStudent(em, texts[1].getText(), texts[2].getText(), texts[3].getText(), texts[0].getText());
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
                
                upButton1.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        pop.hide();
                    }
                });
            }
        });

        JButton dB = new JButton("Delete");
        control.add(dB);
        dB.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel p1 = new JPanel();
                p1.setLayout(new GridLayout(2, 2));

                JLabel jL = new JLabel("Student Number to Delete");
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
                        String msg = removeStudent(em, jT.getText());
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
}