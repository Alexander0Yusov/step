using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            // ax^2+bx+c=0;
            //string insert = Console.ReadLine();
            double x1, x2;

            Console.WriteLine("Введите значение переменной a: ");
            double a = Convert.ToDouble (Console.ReadLine());

            Console.WriteLine("Введите значение переменной b: ");
            double b = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Введите значение переменной c: ");
            double c = Convert.ToDouble(Console.ReadLine());

            double dis = b * b - 4 * a * c;

            double root = Math.Sqrt(dis);
            
            if (root > 0)
            {
                x1 = (-b - root) / (2 * a);
                x2 = (-b + root) / (2 * a);
                Console.WriteLine("x1: ");
                Console.WriteLine( Convert.ToString(x1));
                Console.WriteLine("x1: ");
                Console.WriteLine(Convert.ToString(x2));
            }

            if (root == 0)
            {
                x1 = (-b - root) / (2 * a);
                Console.WriteLine("x: ");
                Console.WriteLine(Convert.ToString(x1));
            }

            if (root < 0)
            {
                Console.WriteLine("Нет корней");
            }

            Console.ReadKey();


        }
    }
}
