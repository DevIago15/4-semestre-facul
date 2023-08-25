using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleEmpresa
{
    class Empresa : Funcionario
    {
        public string NomeEmpresa { get; set; }
        public List<Funcionario> ListFunc { get; set; }

        public Empresa()
        {
            NomeEmpresa = null;
            ListFunc = new List<Funcionario>();
        }

        public void CadastrarEmpresa()
        {
            Console.Write("Nome da Empresa: ");
            NomeEmpresa = Console.ReadLine();
        }

        public string MostrarDados()
        {
            return "\n ---------" + NomeEmpresa + "---------";
        }
        
        public void addFuncionario(Funcionario f)
        {
            ListFunc.Add(f);
        }

        public void delFuncionario(int f)
        {
            ListFunc.RemoveAt(f);
        }

        public override double CalcularSalarioBruto()
        {
            throw new NotImplementedException();
        }

        public override double CalcularSalarioLiquido()
        {
            throw new NotImplementedException();
        }
    }
}
