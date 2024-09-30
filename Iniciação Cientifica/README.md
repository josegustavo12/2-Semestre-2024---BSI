# Introdução ao Qiskit
## Hello World IBM
### Instalação
Seguindo o tutorial da documentação do site: https://docs.quantum.ibm.com/guides/install-qiskit

1. **Criação de um Ambiente Virtual em python**
> https://dev.to/franciscojdsjr/guia-completo-para-usar-o-virtual-environment-venv-no-python-57bo

2. **Ativação do Venv**
> source meu_ambiente_virtual/bin/activate

3. **Instalando o Qiskit SDK e o Qiskit Runtime client**
#### **Qiskit SDK**:
O **Qiskit SDK** é uma biblioteca de código aberto que permite programar, simular e executar algoritmos quânticos em Python. Ele inclui ferramentas para criar circuitos quânticos, simular sua execução localmente ou rodá-los em computadores quânticos reais, como os da IBM Quantum.

#### **Qiskit Runtime Client**:
O **Qiskit Runtime Client** é uma interface que permite executar algoritmos quânticos na nuvem de forma mais eficiente e rápida, reduzindo o tempo de execução e otimizado para algoritmos com muitas iterações. Ele integra-se ao Qiskit SDK para uma experiência fluida.

> pip install qiskit

> pip install qiskit-ibm-runtime

Se você pretende vizualizar funcionalidades no Jupyter Notebook, é recomendado instalar o pacote abaixo

> pip install qiskit[visualization]

4. **Instalando o Jupyter Notebook para executar os códigos**

> pip install jupyter

> jupyter notebook caminho/para/notebook.ipynb


