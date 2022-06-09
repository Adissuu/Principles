using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Assignment_Four_Question_Three
{
    internal static class TextFileProcessor
    {
        public static event EventHandler<string> LineRead;
        public static void Read(string filePath)
        {
            LineRead += TextFileProcessor_LineRead;

            string s = File.ReadAllText(filePath);
            string[] arr = s.Split("\n");
            int line = 1;

            foreach(string str in arr)
            {
                LineRead?.Invoke(null, "Line " + line++ +":");
                Console.WriteLine(str + "\n");

            }

        }

        private static void TextFileProcessor_LineRead(Object o, string s)
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
}
