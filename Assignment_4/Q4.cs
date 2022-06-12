using static TextFileProcessor;
using static MyExtension;
using System.Linq;
using System.Collections.Generic;
using System;

// ---------------------------------------
// COMP 348
// Assignment 4
// Written By: Gabriel Dubois (40209252), Ali Fetanat (40158208), Gabriel D’Alesio(40208868), Liam Daigle(40207583)
// Due June 15, 2022
// ---------------------------------------
class Q4
{
    static List<Shape> shapes = new List<Shape>();
    static void Main(string[] args)
    {
        TextFileProcessor.LineRead += EachLine;

        TextFileProcessor.Read("C:/Users/Gaboubichou/Desktop/Principles/Assignment_4/ShapeList.txt");

        // linq fun startin'
        // Sorting per name and area
        var NameAreaSort =
            from shape in shapes
            orderby shape.GetType().Name, shape.GetArea()
            select shape;
        //print
        Console.Write("Name and area sort:");
        foreach (var x in NameAreaSort)
            Console.WriteLine($"{x.Name},{x.GetArea()}");

        //Linq sorting per perimeter
        var PerimeterSort =
            from shape in shapes
            orderby shape.GetPerimeter()
            select shape;
        // print
        Console.Write("Name and area sort:");
        foreach (var x in PerimeterSort)
            Console.WriteLine($"{x.Name},{x.GetPerimeter()}");

        //Statistics for each type of shape
        var perShape =
                  from shape in shapes
                  group shape by shape.Name into shapeGroup
                  orderby shapeGroup.Key
                  select shapeGroup;

        //Do this for both shape
        perShape.ToList().ForEach(one =>
        {
            int i = 0;
            foreach (var shape in one)
            {
                i++;
            }

            double averageAreaEach = (one.Sum(s => s.GetArea())) / (i);
            Console.WriteLine("Average area for " + one.Key + ": " + averageAreaEach);

            double averagePeriEach = (one.Sum(s => s.GetPerimeter())) / (i);
            Console.WriteLine("Average perimeter for " + one.Key + ": " + averagePeriEach);
        });
        // Final step
        double averageArea = (shapes.Sum(x => x.GetArea()) / shapes.Count);
        double averagePeri = (shapes.Sum(x => x.GetPerimeter()) / shapes.Count);

        Console.WriteLine("\n\nAverage perimeter: " + averagePeri);
        Console.WriteLine("Average area: " + averageArea);
        Console.WriteLine("Total of shapes: " + shapes.Count);

    }
    static void EachLine(string input)
    {
        string[] shapeName = input.Split(',');

        // call correct parse method based on first element on line
        if (shapeName[0] == "Circle")
            shapes.Add(MyExtension.Circ_Parse(input));
        else if (shapeName[0] == "Rectangle")
            shapes.Add(MyExtension.Rec_Parse(input));
    }
}

