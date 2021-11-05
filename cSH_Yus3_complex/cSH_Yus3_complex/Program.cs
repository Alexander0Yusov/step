using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cSH_Yus3_complex
{
    class Complex
    {
        public double _a;
        public double _b;
    
        public Complex()
        {
            _a = 1;
            _b = 1;
        }

        public Complex(double a, double b)
        {
            _a = a;
            _b = b;
        }

        public override string ToString()
        {
            if (_b < 0)
            {
                return $"{_a}-{(-1) * _b}i";
            }
            else
            {
                return $"{_a}+{_b}i";
            }
        }

        public static Complex operator+(Complex c1, Complex c2)
        {
            return new Complex ( c1._a + c2._a, c1._b + c2._b );
        }

        public static Complex operator -(Complex c1, Complex c2)
        {
            return new Complex(c1._a - c2._a, c1._b - c2._b);
        }

        public static Complex operator *(Complex c1, Complex c2)
        {
            return new Complex(c1._a * c2._a - c1._b * c2._b, c1._b * c2._a + c1._a * c2._b);
        }

        public static Complex operator /(Complex c1, Complex c2)
        {
            Complex tmp = new Complex(c2._a, -c2._b);
            Complex tmp1 = c1 * tmp;
            Complex tmp2 = c2 * tmp;
            return new Complex(tmp1._a/tmp2._a, tmp1._b / tmp2._a);
        }

    }



    class Program
    {
        static void Main(string[] args)
        {
            Complex c = new Complex(5,-2);
            Complex c1 = new Complex(4, -4);

            Complex c2 = c + c1;
            Console.WriteLine(c2);

            c2 = c - c1;
            Console.WriteLine(c2);

            c2 = c * c1;
            Console.WriteLine(c2);

            c2 = c / c1;
            Console.WriteLine(c2);

            Console.ReadLine();

        }
    }
}
