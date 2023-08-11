using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2222
{
    public class contaBancaria
    {
        private string nomeCliente;
        private string nroConta;
        private double saldo;


        public contaBancaria()
        {
            nomeCliente = null;
            nroConta = null;
            saldo = 0.0;
        }

        public string NomeCliente
        {
            get { return nomeCliente; }
            set { nomeCliente = value; }
        }

        public string NroConta
        {
            get { return nroConta; }
            set { nroConta = value; }
        }

        public double Saldo
        {
            get { return saldo; }
            set { saldo = value; }
        }


        public virtual void Abertura(double depositoInicial)
        {
            Saldo = depositoInicial;
        }

        public void Depositar(double valor)
        {
            Saldo += valor;
        }

        public virtual void Sacar(double valor)
        {
            Saldo -= valor;
        }

        public double verificaSaldo()
        {
            return Saldo;
        }














    }
}
