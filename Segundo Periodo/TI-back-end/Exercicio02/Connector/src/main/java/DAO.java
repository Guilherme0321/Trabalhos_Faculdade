import java.sql.Statement;
import java.util.ArrayList;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DAO {
	
	private ArrayList<Users> users = new ArrayList<Users>();
	private Connection connection;	

	public DAO(String host, String user, String password) {
		try {
			this.connection = DriverManager.getConnection(host,user,password);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void Atualizar(String tableName,String coluna,String value,int id) {
		String sql = "UPDATE " + tableName + " SET " + coluna + " = ? WHERE id = ?";
		PreparedStatement statement;
			try {
				statement = connection.prepareStatement(sql);
				statement.setString(1, value);
				statement.setInt(2,id);
				statement.executeUpdate();
				System.out.println("Alterado");
			} catch (SQLException e) {
				e.printStackTrace();
			}
	}
	
	public void Deletar(String tableName, int where) {
		String sql = "DELETE from " + tableName + " WHERE id = ?";
			PreparedStatement statement;
			try {
				statement = connection.prepareStatement(sql);
				statement.setInt(1, where);
				statement.executeUpdate();
				System.out.println("Deletado");
			} catch (SQLException e) {
				e.printStackTrace();
			}
	}
	
	public void Inserir(String tableName,String nome, String lastName, String email, String senha) {
		String sql = "INSERT INTO " + tableName + " (nome,ultimo_nome,email,senha) values(?,?,?,?)";
		PreparedStatement statement;
			try {
				statement = connection.prepareStatement(sql);
				statement.setString(1, nome);
				statement.setString(2, lastName);
				statement.setString(3, email);
				statement.setString(4, senha);
				statement.executeUpdate();
				System.out.println("Adicionado!");
			} catch (SQLException e) {
				e.printStackTrace();
			}
	}
	
	public ArrayList<Users> getList(){
		return this.users;
	}
	
	public void Listar(String tabelaName) {
		String sql = "SELECT * FROM " + tabelaName;
		try {
			Statement statement = connection.createStatement();
			ResultSet resul = statement.executeQuery(sql);
			while(resul.next()) {
				Users user = new Users(resul.getInt("id"),resul.getString("nome"),resul.getString("ultimo_nome"),resul.getString("email"),resul.getString("senha"));
				users.add(user);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void Sair() {
		if(connection != null) {
			try {
				connection.close();
				System.out.println("Fim da conexao");
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}

}
