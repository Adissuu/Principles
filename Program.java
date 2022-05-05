import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Scanner reader = null;
        System.out.println("Please enter the name of the file you wish to open.");
        File filename = new File(input.next());
        input.close();
        try {
            reader = new Scanner(filename);
        } catch (FileNotFoundException e) {
            System.out.println("File not found. Program terminating");
            System.exit(0);
        }
        String line = "";
        ArrayList<Shape> shapes = new ArrayList<Shape>();
        while (reader.hasNextLine()) {
            line = reader.nextLine();
            String[] splits = line.split(",");

            if (splits.length == 3)
                shapes.add(Rectangle.parse(line));
            else
                shapes.add(Circle.parse(line));
        }
        reader.close();
        Collections.sort(shapes, new Comparator<Shape>() {
            public int compare(Shape obj1, Shape obj2) {
                if (obj1.getName().compareTo(obj2.getName()) > 0) {
                    return 1;
                } else if (obj1.getName().compareTo(obj2.getName()) < 0) {
                    return -1;
                } else {
                    if (obj1.getArea() > obj2.getArea()) {
                        return 1;
                    } else if (obj1.getArea() < obj2.getArea()) {
                        return -1;
                    }
                }
                return 0;
            }
        });
        for (Shape one : shapes) {
            Printable printable = (Printable) one;
            printable.print();
        }
    }
}
