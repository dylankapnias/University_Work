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

@Embeddable
public class Student implements Serializable {
    //The serialVersionUID is a universal version identifier for a Serializable class
    private static final long serialVersionUID = 1L;
    private String name;
    
    public Student() {
        name = "";
    }
    
    public Student(String in) {
        name = in;
    }
    
    public String getName() {
        return name;
    }
    
    public void setName(String in) {
        name = in;
    }
    
}