using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;


internal static class TextFileProcessor
{
    public delegate void MyEventHandler(string sender);

    public static event MyEventHandler? LineRead;
    public static void Read(string filePath)
    {
        LineRead += TextFileProcessor_LineRead;

        string s = File.ReadAllText(filePath);
        string[] arr = s.Split("\n");
        arr.ToList().ForEach(x => LineRead(x));

    }

    private static void TextFileProcessor_LineRead(string s)
    {
        Console.Write(s + " ");
    }
}

class Driver
{
    static void Main(string[] args)
    {

        TextFileProcessor.Read(@"C:\Users\liamd\source\repos\Assignment_Four_Question_Three\Assignment_Four_Question_Three\Test.txt");
        Console.ReadLine();
    }
}

