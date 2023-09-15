package serviceDAO;

import java.sql.Timestamp;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import modelo.Pessoa;

public class ServicePessoa {
	private Connection con;
	
	public ServicePessoa() {
		String url = "jdbc:postgresql://localhost:5432/Cadastrados";
		String user = "postgres";
		String senha = "senha123";
		try {
			con = DriverManager.getConnection(url,user,senha);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void add(Pessoa pessoa) {
		String sql = "INSERT INTO pessoas (nome, genero, telefone, data_nascimento, nacionalidade, estado_civil, cpf) VALUES (?, ?, ?, ?, ?, ?, ?)";
		try {
			PreparedStatement statemente = con.prepareStatement(sql);
			statemente.setString(1, pessoa.getNome());
			statemente.setString(2,pessoa.getGenero());
			statemente.setString(3,pessoa.getTelefone());
			statemente.setTimestamp(4,Timestamp.valueOf(pessoa.getDataNascionalidade()));
			statemente.setString(5,pessoa.getNacionalidade());
			statemente.setString(6,pessoa.getEstadoCivil());
			statemente.setString(7, pessoa.getCpf());
			
			statemente.executeUpdate();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
}
