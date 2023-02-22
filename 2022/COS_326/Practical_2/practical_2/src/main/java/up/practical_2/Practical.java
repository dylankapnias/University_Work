/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package up.practical_2;

/**
 *
 * @author Dylan Kapnias (u18108467)
 */

import java.io.Serializable;
import javax.persistence.*;

@Entity
public class Practical implements Serializable {
    //The serialVersionUID is a universal version identifier for a Serializable class
    private static final long serialVersionUID = 1L;
    @Id @GeneratedValue long id;
    @Embedded private Student s;
    private String name;
    
    public Practical() {
        s = new Student();
        name = "";
    }
    
    public Practical(String pName, Student stu) {
        s = stu;
        name = pName;
    }
    
    public void setName(String in) {
        name = in;
    }
    
    public String getName() {
        return name;
    }
    
    public long getID() {
        return id;
    }
    
    @ManyToOne @JoinColumn(name = "Student_ID", nullable = false)
    public Student getStudent() {
        return s;
    }
}
