using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContaBancaria
{
    class Program
    {
        static void Main(string[] args)
        {
            double valor = 0;
            int op = 0;
            string msg = null;

            ContaEspecial contaEsp = new ContaEspecial();
            try
            {
                Console.Write("Nome do Cliente: ");
                contaEsp.NomeCliente = Console.ReadLine();

                Console.Write("Numero da Conta: ");
                contaEsp.NroConta = Console.ReadLine();

                Console.Write("Deposito Inicial: ");
                valor = Convert.ToDouble(Console.ReadLine());

                contaEsp.Abertura(valor);
                msg = "Conta Aberta com Sucesso!";
            }
            catch(Exception erro)
            {
                msg = "Erro na Abertura da Conta!" + "Erro: " + erro;
            }
            finally
            {
                Console.WriteLine(msg);
            }

            do
            {
                Console.Write("\n--- MENU --- \n" +
                    "1 - Sacar \n" +
                    "2 - Depositar \n" +
                    "3 - Consultar Saldo \n" +
                    "4 - Finalizar Programa \n" +
                    "Digite sua Opcao: ");
                op = Convert.ToInt32(Console.ReadLine());
                switch (op)
                {
                    case 1:
                        Console.Write("Valor do Saque: ");
                        valor = Convert.ToDouble(Console.ReadLine());
                        contaEsp.Sacar(valor);
                        break;
                    case 2:
                        Console.Write("Valor do seu Deposito: ");
                        valor = Convert.ToDouble(Console.ReadLine());
                        contaEsp.Depositar(valor);
                        break;
                    case 3:
                        Console.WriteLine("\nConsultando seu Saldo... \n" +
                            "Seu Saldo é: R$ " + contaEsp.verificaSaldo());
      
                        break;
                    case 4:
                        Console.WriteLine("Saindo do Programa...");
                        break;
                }
            } while (op != 4);
        }
    }
}
