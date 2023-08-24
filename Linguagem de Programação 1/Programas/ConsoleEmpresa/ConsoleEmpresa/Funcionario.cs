using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleEmpresa
{
    abstract class Funcionario : ICalculcarSalario
    {
        public string NomeFunc { get; set; }
        public Cargo Cargo { get; set; }
        public double SalarioBase { get; set; }
        public double Adicional { get; set; }


        public Funcionario()
        {
            SalarioBase = 0.0;
            Adicional = 0.0;
            Cargo = new Cargo();
        }

        public virtual void LerDadosFuncionario()
        {
            try
            {
                Console.Write("Nome do Funcionário: ");
                NomeFunc = Console.ReadLine();

                Console.Write("Salario Base do Funcionário: R$ ");
                SalarioBase = Convert.ToDouble(Console.ReadLine());

                Console.Write("Adicional do Funcionário: R$ ");
                Adicional = Convert.ToDouble(Console.ReadLine());

                Cargo.LerCargo();
            }
            catch(Exception ex)
            {
                Console.WriteLine("Ocorreu um erro: " + ex);
            }
        }

        public virtual string MostrarFuncionario()
        {
            return "\n ----------- DADOS DO FUNCIONÁRIO ----------- " +
                    "\nNome do Funcionário: " + NomeFunc +
                    "\nSalário Base do Funcionário: " + SalarioBase +
                    "\nValor Adicional: " + Adicional +
                    Cargo.MostrarCargo();
        }
        public abstract double CalcularSalarioBruto();
        public abstract double CalcularSalarioLiquido();

    }
}
