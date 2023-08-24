using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleEmpresa
{
    public class Cargo
    {
        /// prop tab tab, cria variavel e get set automaticamente
        public string Nome { get; set; }
        public string Competencia { get; set; }

        public Cargo()
        {
            Nome = null;
            Competencia = null;
        }

        public void LerCargo()
        {
            Console.Write("Digite o Cargo: ");
            Nome = Console.ReadLine();

            Console.Write("Digite a Competência: ");
            Competencia = Console.ReadLine();
        }

        public string MostrarCargo()
        {
            return "\nCargo: " + Nome +
                "\nCompetência: " + Competencia;
        }




    }









}
