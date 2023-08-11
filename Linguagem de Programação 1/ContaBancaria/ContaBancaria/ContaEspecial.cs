using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2222
{
    public class ContaEspecial : contaBancaria
    {
        private double limite;



        public ContaEspecial() : base()
        {
            limite = 0.0;
        }

        public double Limite
        {
            get { return limite; }
            set { limite = value; }
        }

        public override void Abertura(double depositoInicial)
        {
            string msg = null;
            base.Abertura(depositoInicial);
            try
            {
                Console.WriteLine("Digite o Limite da Conta: ");
                Limite = Convert.ToDouble(Console.ReadLine());
                msg = "Limite Cadastrado com Sucesso!";

            }
            catch (Exception erro)
            {
                msg = "Limite Não Cadastrado com Sucesso \n" +
                    "Erro: " + erro;
            }
            finally
            {
                Console.WriteLine(msg);
            }
        }

        public override void Sacar(double valor)
        {
            if ((base.Saldo + Limite) >= valor)
            {
                base.Sacar(valor);

            }
            else
            {
                Console.WriteLine("Saldo Insuficiente!");
            }
        }
    }

}


