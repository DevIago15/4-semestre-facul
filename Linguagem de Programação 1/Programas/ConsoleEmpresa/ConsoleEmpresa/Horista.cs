using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleEmpresa
{
    class Horista : Funcionario
    {
        public int QtdHoras { get; set; }

        public Horista() : base()
        {
            QtdHoras = 0;
        }

        public override void LerDadosFuncionario()
        {
            base.LerDadosFuncionario();
            try
            {
                Console.Write("Quantidade de Horas Trabalhadas: ");
                QtdHoras = Convert.ToInt32(Console.ReadLine());
            }
            catch(Exception ex)
            {
                Console.WriteLine("Tente novamente! \nErro: " + ex);
            }
        }

        public override string MostrarFuncionario()
        {
            return base.MostrarFuncionario() +
                "\nQuantidade de Horas Trabalhadas: " + QtdHoras +
                "\nSalário Bruto: R$ " + CalcularSalarioBruto() +
                "\nSalário Liquido: R$ " + CalcularSalarioLiquido();
        }

        public override double CalcularSalarioBruto()
        {
            return base.SalarioBase * QtdHoras + base.Adicional;
        }

        public override double CalcularSalarioLiquido()
        {
            return CalcularSalarioBruto() - (CalcularSalarioBruto() * 0.18);
        }
    }
}
