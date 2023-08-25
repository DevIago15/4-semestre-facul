using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleEmpresa
{
    class Mensalista : Funcionario
    {
        public int QdeHoraExtra { get; set; }
        public double ValorHoraExtra { get; set; }

        public Mensalista() :base()
        {
            QdeHoraExtra = 0;
            ValorHoraExtra = 0.0;
        }

        public override void LerDadosFuncionario()
        {
            base.LerDadosFuncionario();
            try
            {
                Console.Write("Quantidade de Horas Extras: ");
                QdeHoraExtra = Convert.ToInt32(Console.ReadLine());

                Console.Write("Valor da Hora Extra: ");
                ValorHoraExtra = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception ex)
            {
                Console.WriteLine("Tente novamente! \nErro: " + ex);
            }
        }

        public override string MostrarFuncionario()
        {
            return base.MostrarFuncionario() +
                "\nQuantidade de Horas Extras Trabalhadas: " + QdeHoraExtra +
                "\nValor da Hora Extra: " + ValorHoraExtra +
                "\nSalário Bruto: R$ " + CalcularSalarioBruto() +
                "\nSalário Liquido: R$ " + CalcularSalarioLiquido();
        }

        public override double CalcularSalarioBruto()
        {
            return base.SalarioBase + (QdeHoraExtra * ValorHoraExtra) + base.Adicional;
        }

        public override double CalcularSalarioLiquido()
        {
            return CalcularSalarioBruto() - (CalcularSalarioBruto() * 0.20);
        }
    }
}
