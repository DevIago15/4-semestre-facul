using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JogoDados
{
    class Jogador
    {
        public string NomeJogador { get; set; }
        public Dado d1 { get; set; }
        public Dado d2{ get; set; }

        public Jogador()
        {
            NomeJogador = null;
            d1 = d1;
            d2 = d2;
        }


        public void criarJogador()
        {
            Console.WriteLine("Escreva o Nome do Jogador: ");
            NomeJogador = Console.ReadLine();
        }
        
        public int Jogar()
        {
            int soma = d1.rolar() + d2.rolar();
            return soma;
        }
    }


}
