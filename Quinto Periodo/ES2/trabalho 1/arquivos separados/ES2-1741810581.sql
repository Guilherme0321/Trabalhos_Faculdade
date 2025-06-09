CREATE TABLE IF NOT EXISTS `Tarefa` (
	`id` int AUTO_INCREMENT NOT NULL UNIQUE,
	`nome` varchar(50) NOT NULL,
	`horas` time NOT NULL,
	`funcionario_matricula` int NOT NULL,
	PRIMARY KEY (`id`)
);

CREATE TABLE IF NOT EXISTS `Funcionário` (
	`matricula` int AUTO_INCREMENT NOT NULL UNIQUE,
	`nome` varchar(50) NOT NULL,
	`cargo` varchar(50) NOT NULL,
	`telefone` varchar(11) NOT NULL,
	`email` varchar(50) NOT NULL,
	PRIMARY KEY (`matricula`)
);

CREATE TABLE IF NOT EXISTS `Projeto` (
	`id` int AUTO_INCREMENT NOT NULL UNIQUE,
	`data-inicio` date NOT NULL,
	`descrição` varchar(255) NOT NULL,
	`data-final` date NOT NULL,
	`funcionario_matricula` int NOT NULL,
	PRIMARY KEY (`id`)
);

CREATE TABLE IF NOT EXISTS `Cliente` (
	`CNPJ` varchar(255) NOT NULL UNIQUE,
	`nome` varchar(50) NOT NULL,
	`endereco` varchar(255) NOT NULL,
	`telefone` varchar(11) NOT NULL,
	`responsavel` varchar(50) NOT NULL,
	`email` varchar(50) NOT NULL,
	PRIMARY KEY (`CNPJ`)
);

ALTER TABLE `Tarefa` ADD CONSTRAINT `Tarefa_fk3` FOREIGN KEY (`funcionario_matricula`) REFERENCES `Funcionário`(`matricula`);

ALTER TABLE `Projeto` ADD CONSTRAINT `Projeto_fk4` FOREIGN KEY (`funcionario_matricula`) REFERENCES `Funcionário`(`matricula`);
