**Projeto: Exchange Cripto – Módulo Administrador
(professor, como comentei com você, esse projeto de investidor, era do meu semestre passsdo, se você analizar esse novo projeto, nas linhas do codigo, vai ver que o projeto desenvolvido agora, esta concetado e funcionando, ou seja, o projeto 4 que foi pedido, foi completo)
Este é o módulo administrativo do sistema de Exchange de Criptomoedas. O administrador pode cadastrar e gerenciar investidores e criptomoedas, além de visualizar informações de saldo e extrato.

 *Funcionalidades:
 
-Login de administrador

-Cadastrar novo investidor

-Excluir investidor

-Cadastrar criptomoeda

-Excluir criptomoeda

-Consultar saldo de investidor

-Consultar extrato de investidor

-Atualizar cotação das criptomoedas (BTC, ETH, XRP)

*Como compilar
Certifique-se de estar na raiz do projeto (ex: ~/Desktop/exchange-cripto-admin).

Execute no terminal (Git Bash ou similar):

gcc admin/src/*.c -Iadmin/include -o admin.exe
 Como executar
Depois de compilar, execute com:

./admin.exe
*Estrutura de pastas

exchange-cripto-admin/
├── admin/
│   ├── include/
│   │   ├── login.h
│   │   ├── investidor.h
│   │   └── criptomoeda.h
│   ├── src/
│   │   ├── login.c
│   │   ├── investidor.c
│   │   ├── criptomoeda.c
│   │   └── main.c
│   └── data/            ← arquivos binários (.dat) são salvos aqui
├── investidor/
│   ├── include/
│   │   └── usuario.h
│   ├── src/
│   │   └── usuario.c
│   └── usuarios.dat     ← onde os dados reais dos investidores são gravados
