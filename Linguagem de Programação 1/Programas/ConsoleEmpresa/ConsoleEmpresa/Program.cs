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
            int op = 0;

            Funcionario funcionario;

            Empresa empresa = new Empresa();
            empresa.CadastrarEmpresa();
            do
            {
                Console.WriteLine("\n --- Bem Vindo a " + empresa.NomeEmpresa + " --- " +
                    "\n1 - Cadastrar Mensalista " +
                    "\n2 - Cadastrar Horista " +
                    "\n3 - Listar Funcionários" +
                    "\n4 - Remover Funcionário " +
                    "\n5 - Sair do Programa ");
                Console.Write("Sua Opção: ");
                try
                {
                    op = Convert.ToInt32(Console.ReadLine());
                    switch (op)
                    {
                        //polimorfismo: objeto funcionario sendo instanciado como horista
                        case 1:
                            funcionario = new Mensalista();
                            funcionario.LerDadosFuncionario();

                            empresa.addFuncionario(funcionario);
                            break;
                        case 2:
                            funcionario = new Horista();
                            funcionario.LerDadosFuncionario();

                            empresa.addFuncionario(funcionario);
                            break;
                        case 3:
                            Console.Clear();
                            Console.WriteLine(empresa.MostrarDados());
                            Console.Write("\n ----------");
                            for (int i = 0; i < empresa.ListFunc.Count; i++)
                            {
                                Console.WriteLine(empresa.ListFunc[i].MostrarFuncionario());
                                Console.Write("\n ----------");
                            }
                            Console.ReadKey(); //trava e obriga pressionar alguma key para fechar o terminal
                            break;
                        case 4:
                            int indice = 0;
                            Console.Write("\nQual Funcionário Deseja Remover? ");
                            indice = Convert.ToInt32(Console.ReadLine());
                            empresa.delFuncionario(indice);
                            break;
                        case 5:
                            Console.WriteLine("Saindo do Programa...");
                            break;
                        default:
                            Console.WriteLine("Opção Invalida\nTente Novamente!");
                            break;
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Ocorreu um erro: " + ex);
                }
            } while (op != 5);
        }
    }
}
