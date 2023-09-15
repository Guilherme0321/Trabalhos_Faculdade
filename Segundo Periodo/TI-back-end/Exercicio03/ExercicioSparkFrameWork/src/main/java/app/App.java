package app;

import static spark.Spark.*;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import modelo.Pessoa;
import serviceDAO.ServicePessoa;

class App {
	public static void main(String[] args) {
		port(8080);
		staticFileLocation("/public");
		get("/", (req,res) -> {
			return null;
		});
		
		post("/pessoa", (req,res) -> {
			String nome = req.queryParams("nome");
			String cpf = req.queryParams("cpf");
			String naciona = req.queryParams("nacionalidade");
			String genero = req.queryParams("genero");
			String telefone = req.queryParams("telefone");
			String estadoCivil = req.queryParams("estado-civil");
			String datanasc = req.queryParams("data-nascimento");
			

			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
			LocalDateTime dataNascimento = LocalDateTime.parse(datanasc, formatter);
			
			Pessoa pessoa = new Pessoa(cpf,nome,naciona,genero,dataNascimento,telefone,estadoCivil);
			ServicePessoa service = new ServicePessoa();
			service.add(pessoa);
			service.close();
			return null;
		});
		
		get("/pessoa/id", (req,res) -> {
			String cpf = req.queryParams("cpf");
			ServicePessoa service = new ServicePessoa();
			Pessoa pessoa = service.getInfoPessoa(cpf);
			service.close();
			return pessoa.toString();
		});
		
		post("/pessoa/alterar", (req,res) -> {
			String cpf = req.queryParams("cpf");
			String nome = req.queryParams("nome");
			String nacionalidade = req.queryParams("nacionalidade");
			String genero = req.queryParams("genero");
			String telefone = req.queryParams("telefone");
			String estado_civil = req.queryParams("estado-civil");
			String datanasc = req.queryParams("data-nascimento");
			
			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
			LocalDateTime dataNascimento = LocalDateTime.parse(datanasc, formatter);
			
			Pessoa pessoa = new Pessoa(cpf,nome,nacionalidade,genero,dataNascimento,telefone,estado_civil);
			ServicePessoa service = new ServicePessoa();
			service.atualizarPessoa(pessoa);
			service.close();
			return null;
		});
		
		get("/pessoa/delete", (req,res) -> {
			String cpf = req.queryParams("cpf");
			ServicePessoa service = new ServicePessoa();
			service.delete(cpf);
			service.close();
			return null;
		});
	}
}
