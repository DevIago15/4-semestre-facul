using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleEmpresa
{
    class Program
    {
        static void Main(string[] args)
        {
            Horista horista = new Horista();
            horista.LerDadosFuncionario();
            Console.WriteLine(horista.MostrarFuncionario());
            Console.ReadKey();

            //cargo.LerCargo();
            //Console.Write(cargo.MostrarCargo());
            //Console.ReadKey(); // trava e obrigado pressionar alguma key para fechar o terminal
        }
    }
}
